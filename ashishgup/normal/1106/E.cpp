#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, k;
int s[N], t[N], d[N], w[N], cache[N][205];
int val[N], nxt[N];
vector<pair<int, int> > events[N];
multiset<pair<int, int> > cur;

int dp(int i, int taken)
{
	if(taken<0)
		return 1e18;
	if(i>=n+1)
		return 0;
	int &ans=cache[i][taken];
	if(ans!=-1)
		return ans;
	ans=min(val[i] + dp(nxt[i], taken), dp(i+1, taken-1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>s[i]>>t[i]>>d[i]>>w[i];
		events[s[i]].push_back({w[i], d[i]});
		events[t[i]+1].push_back({-w[i], d[i]});
	}
	for(int i=1;i<=n;i++)
	{
		for(auto &j:events[i])
		{
			if(j.first>=0)
				cur.insert(j);
			else
				cur.erase(cur.find({-j.first, j.second}));
		}
		if(!cur.size())
		{
			val[i]=0;
			nxt[i]=i+1;
			continue;
		}
		pair<int, int> best = *(--cur.end());
		val[i]=best.first;
		nxt[i]=best.second+1;
	}
	int ans=dp(1, m);
	cout<<ans;
	return 0;
}