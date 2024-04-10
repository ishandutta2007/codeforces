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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], g[MAXN];
int val[MAXN];
int mark[MAXN];
vector<int> G[MAXN], topol;

void dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs(v);
	topol.pb(node);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
	}
	for (int v=1; v<=n; v++) if (!mark[v]) dfs(v);
	memset(mark, 0, sizeof(mark));
	for (int v:topol){
		for (int u:G[v]) mark[g[u]]=v;
		while (mark[g[v]]==v) g[v]++;
		val[g[v]]^=A[v];
	}
	for (int i=n; ~i; i--) if (val[i]){
		for (int v=1; v<=n; v++) if (g[v]==i && (A[v]^val[i])<A[v]){
			A[v]^=val[i];
			for (int u:G[v]){
				A[u]^=val[g[u]];
				val[g[u]]=0;
			}
			break ;
		}
		cout<<"WIN\n";
		for (int v=1; v<=n; v++) cout<<A[v]<<' ';cout<<'\n';
		return 0;
	}
	cout<<"LOSE\n";
	
	return 0;
}