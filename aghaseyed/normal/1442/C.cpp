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
const int mod=998244353;
const int MAXN=300010, T=30;

struct Num{
	ll sum, tav;
	Num(ll s=0, ll t=0){
		sum=s;
		tav=t;
	}
};
bool operator <(Num X, Num Y){
	if (X.tav==Y.tav) return X.sum<Y.sum;
	if (max(X.tav, Y.tav)>=T) return X.tav<Y.tav;
	return X.sum+(1ll<<X.tav)<Y.sum+(1ll<<Y.tav);
}
Num nex1(Num X){
	return Num(X.sum+1, X.tav);
}
Num nex2(Num X){
	return Num(X.sum, X.tav+1);
}
typedef pair<Num, pii> pni;

int n, m, k, u, v, x, y, t, a, b;
bool mark[T+2][MAXN];
Num dist[T+2][MAXN], ans;
priority_queue<pni, vector<pni>, greater<pni>> pq;
vector<int> G[2][MAXN];

inline void upd(int i, int v, Num x){
	if (i>=T){
		if (i&1) i=T+1;
		else i=T;
	}
	if (x<dist[i][v]) pq.push({dist[i][v]=x, {i, v}});
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<T+2; i++) fill(dist[i], dist[i]+MAXN, Num(0, inf));
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		G[0][u].pb(v);
		G[1][v].pb(u);
	}
	upd(0, 1, Num(1, 0));
	while (pq.size()){
		pii p=pq.top().second;
		pq.pop();
		int i=p.first, v=p.second;
		if (mark[i][v]) continue ;
		mark[i][v]=1;
		for (int u:G[i&1][v]) upd(i, u, nex1(dist[i][v]));
		upd(i+1, v, nex2(dist[i][v]));
	}
	
	ans=Num(0, inf);
	for (int i=0; i<=T+1; i++) ans=min(ans, dist[i][n]);
	
	ll res=1;
	while (ans.tav--) res=res*2%mod;
	res=(res + ans.sum -2 + mod)%mod;
	cout<<res<<"\n";
	
	return 0;
}