#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=101;

int n, ct=0;
int a[N], sieve[N], prime[N], nummask[N];
int cache[N][1LL<<17];

int dp(int i, int mask)
{
	if(i==n+1)
		return 0;
	int &ans=cache[i][mask];
	if(ans!=-1)
		return ans;
	ans=abs(a[i]-1) + dp(i+1, mask);
	for(int j=2;j<=60;j++)
	{
		if(!(mask&nummask[j]))
			ans=min(ans, abs(a[i]-j) + dp(i+1, mask|nummask[j]));
	}
	return ans;
}	

void path(int i, int mask)
{
	if(i==n+1)
		return;
	int ans=dp(i, mask);
	if(ans==abs(a[i]-1) + dp(i+1, mask))
	{
		cout<<"1 ";
		return path(i+1, mask);
	}
	for(int j=2;j<=60;j++)
	{
		if(!(mask&nummask[j]))
		{
			if(ans==(abs(a[i]-j) + dp(i+1, mask|nummask[j])))
			{
				cout<<j<<" ";
				return path(i+1, mask|nummask[j]);
			}
		}
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	fill(sieve+1, sieve+N, 1);
	fill(prime+1, prime+N, 1);
	for(int i=2;i<61;i++)
	{
		if(sieve[i])
		{
			for(int j=1;i*j<61;j++)
			{
				sieve[i*j]=0;
				nummask[i*j]|=(1LL<<ct);
			}
			ct++;
		}
	}
	dp(1, 0);
	path(1, 0);
	return 0;
}