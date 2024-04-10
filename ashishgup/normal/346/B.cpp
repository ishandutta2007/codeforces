#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int p, q, r;
string a, b, c;
int lps[N], cache[N][N][N][2];

void compute_lps(string &s)
{
	int n=s.size();
	for(int i=1;i<n;i++)
	{
		int j=lps[i-1];
		while(j>0 && s[i]!=s[j])
			j=lps[j-1];
		if(s[i]==s[j])
			j++;
		lps[i]=j;
	}
}

int dp(int i, int j, int k, int ongoing)
{
	if(k==r)
		return -1e5;
	if(i==p)
		return 0;
	if(j==q)
		return 0;
	int &ans=cache[i][j][k][2];
	if(ans!=-1)
		return ans;
	if(!ongoing)
		ans=max(dp(i+1, j, k, 0), dp(i, j+1, k, 0));
	if(a[i]==b[j])
	{
		if(a[i]==c[k])
		{
			int take=1 + dp(i+1, j+1, k+1, 0);
			ans=max(ans, take);
		}
		else
		{
			int take;
			if(k==0)
				take=1 + dp(i+1, j+1, k, 0);
			else
				take=dp(i, j, lps[k-1], 1);
			ans=max(ans, take);
		}
	}
	return ans;
}

void path(int i, int j, int k, int ongoing)
{
	if(i==p)
		return;
	if(j==q)
		return;
	int ans=dp(i, j, k, ongoing);
	if(ans==0)
		return;
	if(!ongoing)
	{
		if(ans==dp(i+1, j, k, 0))
			return path(i+1, j, k, 0);
		if(ans==dp(i, j+1, k, 0))
			return path(i, j+1, k, 0);
	}
	if(a[i]==b[j])
	{
		if(a[i]==c[k])
		{
			cout<<a[i];
			return path(i+1, j+1, k+1, 0);
		}
		else
		{
			int take;
			if(k==0)
			{
				cout<<a[i];
				return path(i+1, j+1, k, 0);
			}
			else
				return path(i, j, lps[k-1], 1);
		}
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>a>>b>>c;
	p=a.size(), q=b.size(), r=c.size();
	compute_lps(c);
	int ans=dp(0, 0, 0, 0);
	if(ans==0)
		cout<<ans;
	path(0, 0, 0, 0);
	return 0;
}