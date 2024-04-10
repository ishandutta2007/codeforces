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
const int MAXN = 500010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b;
int par[MAXN][LOG], h[MAXN];
int A[MAXN], L[MAXN], R[MAXN];
ll ans[MAXN];
ll ps[MAXN];
vector<int> G[MAXN], vec[MAXN];

void dfs(int node){
	h[node]=h[par[node][0]]+1;
	vec[h[node]].pb(node);
	for (int v:G[node]) dfs(v);
}

int Lca(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[y][i];
	if (x==y) return x;
	for (int i=LOG-1; ~i; i--) if (par[x][i]!=par[y][i]) x=par[x][i], y=par[y][i];
	return par[x][0];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>par[i][0], G[par[i][0]].pb(i);
	for (int j=1; j<LOG; j++) for (int i=1; i<=n; i++) par[i][j]=par[par[i][j-1]][j-1];
	dfs(0);
	for (int lv=2; vec[lv].size(); lv++){
		int m=vec[lv].size()-1;
		
		for (int i=1; i<=m; i++) A[i]=Lca(vec[lv][i-1], vec[lv][i]);
		A[m+1]=0;
		for (int i=1; i<=m; i++) for (L[i]=i-1; L[i] && h[A[L[i]]]>=h[A[i]]; L[i]=L[L[i]]);
		for (int i=m; i; i--) for (R[i]=i+1; R[i]<=m && h[A[R[i]]]>h[A[i]]; R[i]=R[R[i]]);
		
		fill(ps, ps+m+1, 0);
		for (int i=1; i<=m; i++){
			ps[L[i]]+=(R[i]-i)*(h[A[i]]-1ll);
			ps[i]-=(R[i]-i)*(h[A[i]]-1ll);
			ps[i]+=(i-L[i])*(h[A[i]]-1ll);
			ps[R[i]]-=(i-L[i])*(h[A[i]]-1ll);
		}
		for (int i=1; i<=m; i++) ps[i]+=ps[i-1];
		for (int i=0; i<=m; i++) ans[vec[lv][i]]=ans[par[vec[lv][i]][0]] + ps[i] + h[vec[lv][i]]-2;
	}
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
	
	return 0;
}