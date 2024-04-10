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
const int MAXN=1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int P[MAXN], col[MAXN], out[MAXN];
vector<int> G[MAXN], vec[MAXN];

void dfs(int node, int c){
	col[node]=c;
	for (int v:G[node]) if (!col[v]) dfs(v, 3-c);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	if (n%2==0){
		cout<<"First"<<endl;
		for (int i=1; i<=n; i++) cout<<i<<" ";
		for (int i=1; i<=n; i++) cout<<i<<" ";
		cout<<endl;
		cin>>x;
		return 0;
	}
	cout<<"Second"<<endl;
	for (int i=1; i<=2*n; i++) cin>>P[i], vec[P[i]].pb(i);
	for (int i=1; i<=n; i++){
		int u=vec[i][0], v=vec[i][1];
		G[u].pb(v);
		G[v].pb(u);
		u=i, v=i+n;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=2*n; i++) if (!col[i]) dfs(i, 1);
	for (int i=1; i<=2*n; i++) if (col[i]==1) ans=(ans + i)%(2*n);
	assert(ans==0 || ans==n);
	if (ans==0){
		for (int i=1; i<=2*n; i++) if (col[i]==1) out[P[i]]=i;
	}
	if (ans==n){
		for (int i=1; i<=2*n; i++) if (col[i]==2) out[P[i]]=i;
	}
	for (int i=1; i<=n; i++) cout<<out[i]<<" ";
	cout<<endl;
	cin>>x;
	
	return 0;
}