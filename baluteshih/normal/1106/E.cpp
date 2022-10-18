#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct mode
{
	ll l,d,w;
	bool operator<(const mode &a)const{
		if(w!=a.w) return w>a.w;
		if(d!=a.d) return d>a.d;
		return l>a.l;
	}
};
vector<mode> v[100005];
set<mode> s;
ll dp[205][100005];
pll wei[100005];
const ll INF=1e18;

int main()
{jizz
	ll n,m,k,l,r,d,w,ans;
	cin >> n >> m >> k;
	while(k--)
		cin >> l >> r >> d >> w,v[r].pb(mode{l,d+1,w});
	for(ll i=n;i>=1;--i)
	{
		for(auto j:v[i])
			s.insert(j);
		while(!s.empty()&&s.begin()->l>i)
			s.erase(s.begin());
		if(!s.empty())
			wei[i]=MP(s.begin()->w,s.begin()->d);
		else
			wei[i]=MP(0,i+1);
	}
	for(ll i=n;i>=1;--i)
		dp[0][i]=wei[i].F+dp[0][wei[i].S];
	for(ll t=1;t<=m;++t)
		for(ll i=n;i>=1;--i)
			dp[t][i]=min({dp[t-1][i],dp[t-1][i+1],wei[i].F+dp[t][wei[i].S]});
	cout << dp[m][1] << "\n";
}