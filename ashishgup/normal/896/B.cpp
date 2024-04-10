#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=1e3+5;

int n, m, c, cur, loc;
int a[N];

void work()
{
	int lim=c/2 + c%2;
	if(cur>lim)
	{
		for(int i=n;i>=1;i--)
		{
			if(cur>a[i]||!a[i])
			{
				loc=i;
				return;
			}
		}
		loc=1;
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(cur<a[i]||!a[i])
			{
				loc=i;
				return;
			}
		}
		loc=n;
		return;
	}
}

bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
			return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]<a[i-1])
			return 0;
	}
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>c;
	for(int i=1;i<=m;i++)
	{
		cin>>cur;
		work();
		a[loc]=cur;
		cout<<loc<<endl;
		if(check())
			return 0;
	}
	return 0;
}