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
const int mod = 1000000007;
const int MAXN = 500010, LOG=20;

vector<pair<int*, int>> todo;

struct DSU{
	int par[MAXN], parx[MAXN], R[MAXN];
	DSU(){
		memset(parx, 0, sizeof(parx));
		iota(par, par+MAXN, 0);
	}
	
	pii get(int x){
		if (par[x]==x) return {x, 0};
		pii p=get(par[x]);
		p.second^=parx[x];
		return p;
	}
	
	int join(int u, int v, bool tmp=1){
		pii X=get(u);
		pii Y=get(v);
		int w=X.second^Y.second^1, x=X.first, y=Y.first, res=0;
		if (x==y){
			if (w) return -1;
			return 0;
		}
		if (!tmp) return 0;
		if (R[x]<R[y]) swap(x, y);
		
		todo.pb({par+y, par[y]});
		par[y]=x;
		res++;
		
		if (w){
			todo.pb({parx+y, parx[y]});
			parx[y]=1;
			res++;
		}
		
		if (R[x]==R[y]){
			todo.pb({R+x, R[x]});
			R[x]++;
			res++;
		}
		
		return res;
	}
	
} dsu[51];

void undo(int cnt){
	while (cnt--){
		*(todo.back().first)=todo.back().second;
		todo.pop_back();
	}
}

int n, m, k, q, u, v, x, y, t, a, b;
int E[MAXN][3];
int Q[MAXN][2];
bool ans[MAXN];
vector<int> Time[MAXN];
vector<int> seg[MAXN<<2];

void Add(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		seg[id].pb(val);
		return ;
	}
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
}

void dfs(int id, int tl, int tr){
	/*
	cerr<<"dfs "<<tl<<' '<<tr<<"\n";
	debugv(seg[id])
	cerr<<'\n';
	*/
	int cnt=0;
	for (int i:seg[id]) cnt+=max(0, dsu[E[i][2]].join(E[i][0], E[i][1]));
	if (tr-tl==1){
		ans[tl]=dsu[Q[tl][1]].join(E[Q[tl][0]][0], E[Q[tl][0]][1], 0)+1;
		if (ans[tl]) E[Q[tl][0]][2]=Q[tl][1];
	}
	else{
		int mid=(tl+tr)>>1;
		dfs(id<<1, tl, mid);
		dfs(id<<1 | 1, mid, tr);
	}
	
	undo(cnt);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k>>q;
	for (int i=1; i<=m; i++) cin>>E[i][0]>>E[i][1];
	for (int i=1; i<=q; i++){
		cin>>Q[i][0]>>Q[i][1];
		Time[Q[i][0]].pb(i);
	}
	for (int i=1; i<=m; i++){
		Time[i].pb(q+1);
		for (int j=0; j+1<Time[i].size(); j++) Add(1, 1, q+1, Time[i][j]+1, Time[i][j+1], i);
	}
	dfs(1, 1, q+1);
	for (int i=1; i<=q; i++) cout<<(ans[i]?"YES\n":"NO\n");
	
	return 0;
}
/*
4 5 2 6
1 2
2 3
1 3
1 4
3 4

1 1
2 1
4 2
5 2
3 1
3 2
*/