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
const int MAXN = 200010, LOG=30;

inline int highbit(int x){
	return 31-__builtin_clz(x);
}

vector<pair<int*, int>> todo; 
struct Gauss{
	int gauss[LOG];
	Gauss(){
		memset(gauss, 0, sizeof(gauss));
	}
	int Add(int x){
		for (int i=LOG-1; ~i; i--) x=min(x, x^gauss[i]);
		if (!x) return 0;
		int cnt=0;
		int bit=highbit(x);
		
		for (int i=0; i<LOG; i++) if (gauss[i]&(1<<bit)){
			todo.pb({gauss+i, gauss[i]});
			cnt++;
			gauss[i]^=x;
		}
		todo.pb({gauss+bit, gauss[bit]});
		cnt++;
		gauss[bit]=x;
		return cnt;
	}
	int Get(int x){
		for (int i=LOG-1; ~i; i--) x=min(x, x^gauss[i]);
		return x;
	}
} gauss;

struct Dsu{
	int par[MAXN], parx[MAXN], R[MAXN];
	Dsu(){
		memset(R, 0, sizeof(R));
		memset(parx, 0, sizeof(parx));
		iota(par, par+MAXN, 0);
	}
	pii Get(int x){
		if (par[x]==x) return {x, 0};
		pii p=Get(par[x]);
		p.second^=parx[x];
		return p;
	}
	
	int Join(int x, int y, int w){
		pii X=Get(x);
		pii Y=Get(y);
		x=X.first;
		y=Y.first;
		w^=X.second^Y.second;
		if (x==y) return gauss.Add(w);
		
		int cnt=0;
		if (R[x]<R[y]) swap(x, y);
		
		if (R[x]==R[y]){
			todo.pb({R+x, R[x]});
			cnt++;
			R[x]++;
		}
		todo.pb({par+y, par[y]});
		cnt++;
		par[y]=x;
		
		todo.pb({parx+y, parx[y]});
		cnt++;
		parx[y]=w;
		
		return cnt;
	}
} dsu;


int n, m, k, u, v, x, y, t, a, b;
int Q[MAXN][3];
map<pii, int> W, Time;
vector<piii> seg[MAXN<<2];

void Add(int id, int tl, int tr, int l, int r, piii p){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		seg[id].pb(p);
		return ;
	}
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, p);
	Add(id<<1 | 1, mid, tr, l, r, p);
}

void undo(int cnt){
	while (cnt--){
		(*todo.back().first)=todo.back().second;
		todo.pop_back();
	}
}

void dfs(int id, int tl, int tr){
	int cnt=0;
	for (piii p:seg[id]) cnt+=dsu.Join(p.first.first, p.first.second, p.second);
	
	if (tr-tl>1){
		int mid=(tl+tr)>>1;
		dfs(id<<1, tl, mid);
		dfs(id<<1 | 1, mid, tr);
	}
	else if (Q[tl][0]==3){
		int x=Q[tl][1], y=Q[tl][2];
		int w=dsu.Get(x).second^dsu.Get(y).second;
		cout<<gauss.Get(w)<<'\n';
	}
	
	undo(cnt);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>x>>y;
		if (x>y) swap(x, y);
		cin>>W[{x, y}];
		Time[{x, y}]=1;
	}
	cin>>m;
	
	for (int i=1; i<=m; i++){
		cin>>Q[i][0];
		if (Q[i][0]==3){
			cin>>Q[i][1]>>Q[i][2];
			continue ;
		}
		cin>>x>>y;
		if (x>y) swap(x, y);
		if (Q[i][0]==1){
			Time[{x, y}]=i;
			cin>>W[{x, y}];
		}
		else{
			Add(1, 1, m+1, Time[{x, y}], i, {{x, y}, W[{x, y}]});
			Time.erase({x, y});
		}
	}
	for (auto p:Time) Add(1, 1, m+1, p.second, m+1, {p.first, W[p.first]});
	
	dfs(1, 1, m+1);
	
	return 0;
}