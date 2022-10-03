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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)
 
const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=998244353;
const int MAXN=200010;
 
int n, m, k, u, v, x, y, t, a, b, sz;
int sieve[MAXN];
ll A[MAXN];
vector<pair<int, pii>> G[MAXN];
map<int, int> mp[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
void Merge(int x, int y){
	if (SZ(mp[x])<SZ(mp[y])) mp[x].swap(mp[y]);
	for (pii p:mp[y]) mp[x][p.first]=max(mp[x][p.first], p.second);
	mp[y].clear();
}
void dfs(int node, int par){
	for (auto p:G[node]) if (p.first!=par){
		int v=p.first;
		ll y=p.second.first, x=p.second.second;
		A[v]=x*powmod(y, mod-2)%mod*A[node]%mod;
		dfs(v, node);
		while (y>1){
			int p=sieve[y];
			mp[v][p]++;
			y/=p;
		}
		while (x>1){
			int p=sieve[x];
			if (mp[v][p]) mp[v][p]--;
			x/=p;
		}
		
		Merge(node, v);
	}
}

int Main(){
	cin>>n;
	for (int i=1; i<=n; i++) G[i].clear(), mp[i].clear();
	for (int i=1; i<n; i++){
		cin>>u>>v>>x>>y;
		int g=__gcd(x, y);
		x/=g;
		y/=g;
		G[u].pb({v, {x, y}});
		G[v].pb({u, {y, x}});
	}
	A[1]=1;
	dfs(1, 0);
	
//	debug(A[1])
//	debug(A[2])
//	debug(A[3])
//	debug(A[4])
	
	ll res=1;
	for (pii p:mp[1]){
		while (p.second--) res=res*p.first%mod;
	}
	
//	for (int i=1; i<=n; i++) debug2(i, A[i]*res%mod)
	
	ll sum=0;
	for (int i=1; i<=n; i++) sum+=A[i];
	sum%=mod;
//	debug2(res, sum)
	cout<<sum*res%mod<<"\n";
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i; j<MAXN; j+=i) sieve[j]=i;
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
8
5 4 2 3
6 4 5 4
1 3 5 2
6 8 2 1
3 5 3 4
3 2 2 5
6 7 4 3


*/