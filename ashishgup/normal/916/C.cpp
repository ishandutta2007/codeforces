#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6;

int sieve[N+1];
vector<pair<int, int> > g[N];

int32_t main()
{
	IOS;
	vector<int> primes;
	for(int i=2;i<=N;i++)
		sieve[i]=1;
	for(int i=2;i<=N;i++)
	{
		if(sieve[i])
		{
			primes.push_back(i);
			for(int j=2;i*j<=N;j++)
			{
				sieve[i*j]=0;
			}
		}
	}
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n-2;i++)
	{
		g[i].push_back(make_pair(i+1, 1));
	}
	int reqd=*(upper_bound(primes.begin(), primes.end(), n-2));
	reqd-=(n-2);
	g[n-1].push_back(make_pair(n, reqd));
	int rest=1e9;
	int extra=(m-(n-1));
	for(int i=1;i<=n-1;i++)
	{
		if(extra==0)
			break;
		for(int j=i+2;j<=n;j++)
		{
			if(extra==0)
				break;
			extra--;
			g[i].push_back(make_pair(j, rest));
		}
	}
	int ans=reqd+n-2;
	cout<<ans<<" "<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		for(auto it:g[i])
		{
			cout<<i<<" "<<it.first<<" "<<it.second<<endl;
		}
	}
	return 0;
}