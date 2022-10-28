#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int MOD=1e9+7;

int n, m, ctr=0;
int s[N], t[N], dp[N];
map<int, int> comp;
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s[i]>>t[i];
		comp[s[i]];
		comp[t[i]];
	}
	comp[0];
	comp[n];
	for(auto &it:comp)
		it.second=++ctr;
	for(int i=1;i<=m;i++)
	{
		s[i]=comp[s[i]], t[i]=comp[t[i]];
		g[t[i]].push_back(s[i]);
	}
	dp[1]=1;
	for(int i=2;i<=ctr;i++)
	{
		int ans=0;
		for(auto &it:g[i])
			ans+=(dp[i-1] - dp[it-1]);
		ans%=MOD;
		ans+=MOD;
		ans%=MOD;
		dp[i]=dp[i-1] + ans;
		dp[i]%=MOD;
	}
	int ans=dp[ctr] - dp[ctr-1] + MOD;
	ans%=MOD;
	cout<<ans;
	return 0;
}