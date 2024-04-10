#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int count=0;
	int a,b;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		if(a>0 && i<(k-1))
		{
			count++;
		}
		else if(i==(k-1))
		{
			b=a;
			if(a>0)
			{
				count++;
			}
		}
		else if(i>(k-1))
		{
			if((b>0) && (a==b))
			{
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}