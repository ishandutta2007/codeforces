#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,h;
	cin>>n>>h;
	vector<int> v(n);
	for(int i=0; i<n ; i++)
	{
		cin>>v[i];
	}
	int count=0;
	for(int i=0; i<n ; i++)
	{
		if(v[i]>h)
		{
			count+=2;
		}
		else
		{
			count++;
		}
	}
	cout<<count;
	return 0;
}