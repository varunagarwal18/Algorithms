#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text, pattern;
	cin>> text>> pattern;
	int n = pattern.size();
	int arr[n]={0};
	
	int index=0, i;
	for( i=1; i<n; )
	{
		if(pattern[i]==pattern[index])
		{
			arr[i]=index+1;
			index++;
			i++;
		}
		else
		{
			if(index==0)
			{
				arr[i]=0;
				i++;
			}
			else
			{
				index = arr[index-1];
			}
		}
	}
	
	i=0; index=0;
	while(i<text.size() && index<n)
	{
		if( text[i] == pattern[index])
		{
			i++;
			index++;
		}
		else
		{
			if(index==0)
			{
				i++;
			}
			else
			{
				index = arr[index-1];
			}
		}
	}
	
	if(index == n) cout<<"Pattern exists in given text";
	else  cout<<"Pattern does not exist in given text";
}


