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
#define get(x, y) (((x)>>(y))&1)

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=50010, N=8;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
int par[MAXN], h[MAXN], par2[MAXN];
int ans[1<<N][MAXN];
int TR[N<<N][2], val[N<<N], ts=0;
vector<int> G[MAXN];

void dfs(int node){
	h[node]=h[par[node]]+1;
	for (int v:G[node]) if (v!=par[node]){
		par[v]=node;
		dfs(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1);
	for (int i=1; i<=n; i++) if (h[i]>=(1<<N)){
		memset(TR, 0, sizeof(TR));
		memset(val, -1, sizeof(val));
		ts=0;
		int j=i;
		for (int t=0; t<(1<<N); t++, j=par[j]){
			int v=0, num=A[j]^t;
			for (int b=2*N-1; b>=N; b--){
				int c=get(num, b);
				if (!TR[v][c]) TR[v][c]=++ts;
				v=TR[v][c];
			}
//			if (i==4) debug2(j, num)
			num&=(1<<N)-1;
			val[v]=max(val[v], num);
		}/*
		if (i==4){
			debug(ts)
			for (int i=0; i<=ts; i++) cerr<<i<<" : "<<TR[i][0]<<" "<<TR[i][1]<<"\n";
		}*/
		par2[i]=j;
		for (int num=0; num<(1<<N); num++){
			int res=0, v=0;
			for (int b=N-1; ~b; b--){
				int c=get(num, b)^1;
				if (TR[v][c]) res|=(1<<b);
				else c^=1;
				v=TR[v][c];
			}/*
			if (i==4 && num==0){
				debug(res)
				debug(val[v])
			}*/
			res=((res<<N)|val[v]);
			ans[num][i]=res;
		}
	}/*
	debug(ans[0][4])
	debug(par2[4])
	*/
	
	while (m--){
		cin>>u>>v;
		u=par[u];
		int hv=h[v], res=0;
		while (v^u){
			if (h[v]-(1<<N)>=h[u]){
				res=max(res, ans[(hv-h[v])>>N][v]);
				v=par2[v];
				continue ;
			}
			res=max(res, (hv-h[v])^A[v]);
			v=par[v];
		}
		cout<<res<<"\n";
	}
	
	return 0;
}