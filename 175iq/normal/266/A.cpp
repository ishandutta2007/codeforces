#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n ; 
	cin>>n ;
	string s1 ;
	cin>>s1 ;
	char memory = s1[0] ;
	int count=0 ;
	for (int i = 1; i < s1.size(); i++)
	{
		while(s1[i]==memory)
		{
			count++;
			i++;
		}
		memory=s1[i];
	}
	cout<<count;
	return 0;
}