// result of hard work!
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
const int MAXN = 100010, LOG=18;

int n, m, k, u, v, x, y, t, a, b, root;
int stt[MAXN], fnt[MAXN], timer=1;
int par[MAXN][LOG], h[MAXN];
int fen[MAXN], good[MAXN];
int T[MAXN], A[MAXN], B[MAXN], C[MAXN], K[MAXN], Y[MAXN];
int Dwn[MAXN], Up[MAXN], Dist[MAXN], val[MAXN];
vector<int> G[MAXN];
vector<pair<pii, int>> Q[MAXN];

void dfs1(int node){
	stt[node]=timer++;
	for (int v:G[node]) h[v]=h[node]+1, dfs1(v);
	fnt[node]=timer;
}

inline bool is_par(int u, int v){
	return stt[u]<=stt[v] && fnt[v]<=fnt[u];
}

int Lca(int x, int y){
	if (stt[x]>stt[y]) swap(x, y);
	if (is_par(x, y)) return x;
	for (int i=LOG-1; i>=0; i--) if (!is_par(par[x][i], y)) x=par[x][i];
	return par[x][0];
}

inline int GetPar(int v, int k){
	for (int i=0; i<LOG; i++) if (k&(1<<i)) v=par[v][i];
	return v;
}

int GetKth(int u, int v, int k){ // 0-based (k=0 ==> u)
	int lca=Lca(u, v);
	if (h[u]-h[lca]==k) return lca;
	if (h[u]-h[lca]>k) return GetPar(u, k);
	k-=h[u]-h[lca];
	return GetPar(v, h[v]-h[lca]-k);
}

inline void add(int pos, int x){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=x;
}
inline int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>par[i][0];
		G[par[i][0]].pb(i);
	}
	for (int j=1; j<LOG; j++) for (int i=1; i<=n; i++) par[i][j]=par[par[i][j-1]][j-1];
	dfs1(0);
	
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>T[i];
		if (T[i]==1) cin>>C[i];
		else{
			cin>>A[i]>>B[i]>>K[i]>>Y[i];
			
			A[i]=GetKth(A[i], B[i], 1);
			if (A[i]==B[i]){
				Dwn[i]=Up[i]=inf;
				continue ;
			}
			B[i]=GetKth(B[i], A[i], 1);
			Dist[i]=h[A[i]]+h[B[i]]-2*h[Lca(A[i], B[i])];
			Dwn[i]=-1;
			Up[i]=Dist[i]+1;
		}
	}
	
	int flag=1;
	while (flag--){
		for (int i=0; i<MAXN; i++) Q[i].clear();
		for (int i=1; i<=m; i++) if (T[i]==2){
			if (Up[i]-Dwn[i]<2) continue ;
			flag=1;
			int mid=(Dwn[i]+Up[i])>>1;
			int u=A[i], v=GetKth(A[i], B[i], mid);			
			Q[Y[i]].pb({{u, v}, i});
			Q[i].pb({{u, v}, i});
			val[i]=mid+1;
		}
		
		memset(fen, 0, sizeof(fen));
		for (int i=1; i<=m; i++){
			if (T[i]==1){
				add(stt[C[i]], +1);
				add(fnt[C[i]], -1);
			}
			for (auto p:Q[i]){
				int u=p.first.first, v=p.first.second, id=p.second;
				int lca=Lca(u, v), tmp=get(stt[u])+get(stt[v])-get(stt[lca])-get(stt[par[lca][0]]);
				if (id==i) tmp=-tmp;
				val[id]+=tmp;
			}
		}
		
		for (int i=1; i<=m; i++) if (T[i]==2){
			if (Up[i]-Dwn[i]<2) continue ;
			int mid=(Dwn[i]+Up[i])>>1;
			if (val[i]>=K[i]) Up[i]=mid;
			else Dwn[i]=mid;
		}
		
	}
	
	
	for (int i=1; i<=m; i++) if (T[i]==2){
		if (Up[i]<=Dist[i]) cout<<GetKth(A[i], B[i], Up[i])<<'\n';
		else cout<<"-1\n";
	}
	
	return 0;
}