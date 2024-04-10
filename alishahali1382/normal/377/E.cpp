#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, S, sz;
pll A[MAXN], dp[MAXN];
pair<ll, pll> B[MAXN];

inline ll Inter(pll a, pll b){
	if (a.first==b.first) return (a.second<=b.first?-INF:INF);
	return (a.second-b.second)/(b.first-a.first) + ((a.second-b.second)%(b.first-a.first)>0);
}
inline void Add(pll x){
	while (sz && Inter(B[sz-1].second, x)<=B[sz-1].first) sz--;
	if (!sz) B[sz++]={-INF, x};
	else B[sz]={Inter(B[sz-1].second, x), x}, sz++;
}
inline ll Get(ll x){
	pll p=(upper_bound(B, B+sz, make_pair(x, pll(INF, INF)))-1)->second;
	return p.first*x + p.second;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>m>>S;
	for (int i=1; i<=m; i++) cin>>A[i].second>>A[i].first;
	sort(A+1, A+m+1);
	for (int i=1; i<=m; i++) if (!n || A[i].second>A[n].second) A[++n]=A[i];
	assert(A[1].first==0);
	A[n+1]={S, 0};
	dp[1]={0, 0};
	Add({A[1].second, 0});
	for (int i=2; i<=n+1; i++){
		ll dwn=dp[i-1].first-1, up=100000000;
		while (up-dwn>1){
			ll mid=(dwn+up)>>1, x=Get(mid);
			if (x<A[i].first) dwn=mid;
			else up=mid;
		}
		ll x=Get(up);
		dp[i]={up, x-A[i].first};
		Add({A[i].second, dp[i].second-dp[i].first*A[i].second});
//		debugp(dp[i])
	}
	ll ans=INF;
	for (int i=1; i<=n; i++) ans=min(ans, dp[i].first + (S-dp[i].second+A[i].second-1)/A[i].second);
	cout<<ans<<"\n";
	
	return 0;
}