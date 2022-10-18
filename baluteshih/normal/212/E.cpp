#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#endif

vector<pii> ans;
vector<int> wei[5005];
vector<int> G[5005];
int x,y,w[5005],n;
bitset<5005> dp,can;

void dfs(int u,int f)
{
	w[u]=1;
	for(int i:G[u])
		if(i!=f)
			dfs(i,u),wei[u].pb(w[i]),w[u]+=w[i];
	wei[u].pb(n-w[u]);
}

int main()
{
	IOS()
	int a,b;
	cin >> n;
	for(int i=1;i<n;++i)
		cin >> a >> b,G[a].pb(b),G[b].pb(a);
	dfs(1,1);
	for(int i=1;i<=n;++i)
	{
		dp.reset(),dp[0]=1;
		for(int j:wei[i])
			dp=dp<<j|dp;
		can|=dp;
	}
	for(int i=1;i<n-1;++i)
		if(can[i]) ans.pb(pii(i,n-1-i));
	cout << ans.size() << "\n";
	for(pii i:ans)
		cout << i.X << " " << i.Y << "\n";
}