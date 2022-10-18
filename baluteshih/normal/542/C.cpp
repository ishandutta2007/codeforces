#pragma GCC optimize("O3")
#include<utility>
#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
#include<cmath>
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

ll t[205],dp[205][205];
const ll INF=1e9;

int main()
{
	IOS()
	ll n,ans=1,ans2=0,g;
	cin >> n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=INF;
	for(int i=1;i<=n;++i)
		cin >> t[i],dp[i][t[i]]=1;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1;i<=n;++i)
		if(dp[i][i]!=INF)
			g=__gcd(ans,dp[i][i]),ans*=dp[i][i]/g;
		else
		{
			ll cnt=-1;
			for(int x=i;dp[x][x]==INF;x=t[x])
				++cnt;
			ans2=max(ans2,cnt);
		}
	cout << (ans2/ans+1)*ans << "\n";
}