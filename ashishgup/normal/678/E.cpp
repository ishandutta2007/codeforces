#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=19;

int n;
int vis[N][1LL<<N];
double p[N][N], cache[N][1LL<<N];

double dp(int idx, int mask)
{
	if(__builtin_popcount(mask)==n)
		return 1;
	double &prob=cache[idx][mask];
	if(vis[idx][mask])
		return prob;
	vis[idx][mask]=1;
	prob=0;
	for(int i=1;i<=n;i++)
	{
		if(mask&(1LL<<i))
			continue;
		if(idx==1)
			prob=max(prob, p[idx][i]*dp(idx, mask|1LL<<i));
		else if(i==1)
			prob=max(prob, p[i][idx]*dp(i, mask|1LL<<i));
		else
			prob=max(prob, p[idx][i]*dp(idx, mask|1LL<<i) + p[i][idx]*dp(i, mask|1LL<<i));
	}
	return prob;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>p[i][j];
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans, dp(i, 1LL<<i));
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}