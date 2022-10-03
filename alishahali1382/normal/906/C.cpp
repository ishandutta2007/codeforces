#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int N = 22;

int n, m, k, u, v, x, y, t, a, b, ans, ansmask;
int adj[N];
bool ok[1<<N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	if (m==n*(n-1)/2) kill(0)
	while (m--){
		cin>>u>>v;
		u--;
		v--;
		adj[u]|=(1<<v);
		adj[v]|=(1<<u);
	}
	for (int mask=0; mask<(1<<n); mask++){
		if (__builtin_popcount(mask)<2) ok[mask]=1;
		for (int v=0; v<n && !ok[mask]; v++) if (mask&(1<<v)) ok[mask]|=(ok[mask^(1<<v)] && (adj[v]&mask));
	}
	ans=n;
	ansmask=(1<<n)-1;
	for (int mask=0; mask<(1<<n); mask++) if (__builtin_popcount(mask)<ans && ok[mask]){
		int tmp=mask;
		for (int v=0; v<n; v++) if (mask&(1<<v)) tmp|=adj[v];
		if (tmp!=(1<<n)-1) continue ;
		ans=__builtin_popcount(mask);
		ansmask=mask;
	}
	cout<<ans<<'\n';
	for (int v=0; v<n; v++) if (ansmask&(1<<v)) cout<<v+1<<' ';
	
	return 0;
}