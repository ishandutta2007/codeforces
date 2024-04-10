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
const int mod=1000000007;
const int MAXN=300010;

int n, m, k, u, v, x, y, t, a, b;
int par[MAXN];
ll S[MAXN], ans;
vector<int> G[MAXN];

ll dfs(int node, ll k){
//	debug2(node, k)
	ans+=k*S[node];
	int deg=SZ(G[node]);
	if (!deg) return S[node];
	vector<ll> vec;
	for (int v:G[node]) vec.pb(dfs(v, k/deg));
	sort(all(vec));
	reverse(all(vec));
	for (int i=0; i<k%deg; i++) ans+=vec[i];
	return vec[k%deg]+S[node];
}

int Main(){
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		G[i].clear();
	}
	for (int i=2; i<=n; i++){
		cin>>par[i];
		G[par[i]].pb(i);
	}
	for (int i=1; i<=n; i++) cin>>S[i];
	ans=0;
	dfs(1, k);
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
5 4
1 2 1 3
6 2 1 5 7

*/