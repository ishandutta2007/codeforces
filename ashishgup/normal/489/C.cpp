#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=3e5+5;

int a[N], b[N];

int32_t main()
{
	int m, s;
	cin>>m>>s;
	if(m==1&&s==0)
	{
		cout<<"0 0";
		return 0;
	}
	if(s==0)
	{
		cout<<"-1 -1";
		return 0;
	}
	a[1]=1;
	int rem=s-1;
	for(int i=m;i>=1;i--)
	{
		if(i!=1)
		{
			a[i]+=min(9, rem);
			rem-=min(9, rem);
		}
		else
		{
			a[i]+=min(8, rem);
			rem-=min(8, rem);
		}
	}
	if(rem!=0)
	{
		cout<<"-1 -1";
		return 0;
	}
	b[1]=1;
	rem=s-1;
	for(int i=1;i<=m;i++)
	{
		if(i!=1)
		{
			b[i]+=min(9, rem);
			rem-=min(9, rem);
		}
		else
		{
			b[i]+=min(8, rem);
			rem-=min(8, rem);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i];
	}
	cout<<" ";
	for(int i=1;i<=m;i++)
	{
		cout<<b[i];
	}
}