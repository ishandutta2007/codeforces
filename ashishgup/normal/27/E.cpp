#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int INF=1e18;

int n;
vector<int> v;
vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int cache[15][1<<10];

int dp(int i, int mask)
{
	if(mask == ((1<<n) - 1))
		return 1;
	if(i==n)
		return 2e18;
	int &ans=cache[i][mask];
	if(ans!=-1)
		return ans;
	ans=2e18;
	vector<pair<int, int> > cur;
	for(int j=0;j<n;j++)
	{
		if(!((mask>>j) & 1))
			cur.push_back({v[j], j});
	}
	int m=cur.size();
	for(int j=0;j<(1<<m);j++)
	{
		int actualmask=0;
		int pwr=1;
		for(int k=0;k<m;k++)
		{
			if((j>>k) & 1)
			{
				pwr*=cur[k].first;
				actualmask|=(1<<cur[k].second);
			}
		}
		pwr--;
		if(pwr==0)
			continue;
		int store=1;
		bool check=1;
		for(int k=1;k<=pwr;k++)
		{
			if(store>INF/primes[i])
			{
				check=0;
				break;
			}
			store*=primes[i];
		}
		if(!check)
			continue;
		int next=dp(i+1, mask|actualmask);
		if(store > INF/next)
			continue;
		ans=min(ans, store*next);
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=2;i*i<=n;i++)
	{
		while(n%i==0)
		{
			v.push_back(i);
			n/=i;
		}
	}
	if(n>1)
		v.push_back(n);
	n=v.size();
	int ans=dp(0, 0);
	cout<<ans;
	return 0;
}