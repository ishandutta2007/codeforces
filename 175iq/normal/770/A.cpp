#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	char c = 'a';
	int r = n/k ;
	int p = n%k;

	string s;
	for(int i=0; i<k; i++)
	{
		s+=c;
		c++;
	}
	
	for(int i=0; i<r; i++)
	{
		cout<<s;
	}

	c='a';

	for(int i=0; i<p; i++)
	{
		cout<<c;
		c++;
	}	
	return 0;
}