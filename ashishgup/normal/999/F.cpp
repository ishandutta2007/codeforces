#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
int c[N], f[N], h[N], freq[N], people[N];
int cache[5005][505];

int dp(int left, int ppl)
{
	if(left==0||ppl==0)
		return 0;
	int &ans=cache[left][ppl];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int j=1;j<=min(left, k);j++)
	{
		ans=max(ans, h[j] + dp(left-j, ppl-1));
	}
	return ans;
}

int32_t main()
{
	IOS; 
	cin>>n>>k;
	for(int i=1;i<=n*k;i++)
	{
		cin>>c[i];
		freq[c[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		people[f[i]]++;
	}
	for(int i=1;i<=k;i++)
		cin>>h[i];  
	int ans=0;
	for(int i=1;i<=1e5;i++)
	{
		if(!people[i])
			continue;
		for(int j=1;j<=freq[i];j++)
		{
			for(int kk=1;kk<=people[i];kk++)
			{
				cache[j][kk]=-1;
			}
		}
		ans+=dp(freq[i], people[i]);
	}
	cout<<ans;
	return 0;   
}