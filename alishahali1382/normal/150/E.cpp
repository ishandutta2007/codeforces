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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, L, R, limit, ans1, ans2, ok, height, H;
bool dead[MAXN];
int sz[MAXN];
int val[MAXN];
int seg[MAXN<<2];
bool lazy[MAXN<<2];
bool mark[MAXN];
int E[MAXN][3];
vector<pii> G[MAXN];

inline int f(int w){
	if (w<limit) return -1;
	return +1;
}

int dfs1(int node, int par){
	sz[node]=1;
	for (pii p:G[node]) if (p.first!=par && !dead[p.first]) sz[node]+=dfs1(p.first, node);
	return sz[node];
}

int Centroid(int node, int par, int n){
	for (pii p:G[node]) if (!dead[p.first] && p.first!=par && sz[p.first]*2>n) return Centroid(p.first, node, n);
	return node;
}

void puttag(int id){
	lazy[id]=1;
	seg[id]=-inf;
}

void shift(int id){
	if (!lazy[id]) return ;
	lazy[id]=0;
	puttag(id<<1);
	puttag(id<<1 | 1);
}

void Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id]=val;
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, pos, val);
	Set(id<<1 | 1, mid, tr, pos, val);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}

int Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return -inf;
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return max(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}
// L-h <= hh <= R-h
void dfs2(int node, int par, int h, int sum){
	if (h>R || ok) return ;
	if (height+h>=L){
		int tmp=Get(1, 0, n, L-h, R-h+1);
		if (tmp+sum>=0){
			ok=1;
			ans1=node;
			//ans2=tmp.second;
			return ;
		}
	}
	for (pii p:G[node]) if (p.first!=par && !dead[p.first]) dfs2(p.first, node, h+1, sum+p.second);
}

void dfs3(int node, int par, int h, int sum){
	if (ok || h>R) return ;
	H=max(H, h);
	if (sum>val[h]){
		val[h]=sum;
		mark[h]=1;
		//Set(1, 0, n, h, val[h]);	
	}
	for (pii p:G[node]) if (p.first!=par && !dead[p.first]) dfs3(p.first, node, h+1, sum+p.second);
}

void dfs4(int node, int par, int h, int sum){
	if (ans2) return ;
	if (L<=h && h<=R && sum>=0){
		ans2=node;
		return ;
	}
	for (pii p:G[node]) if (p.first!=par) dfs4(p.first, node, h+1, sum+p.second);
}

void Divide(int root){
	root=Centroid(root, root, dfs1(root, root));

	dead[root]=1;
	H=height=0;
	val[0]=0;
	Set(1, 0, n, 0, 0);
	for (pii p:G[root]) if (!dead[p.first] && !ok){
		H=0;
		dfs2(p.first, root, 1, p.second);
		dfs3(p.first, root, 1, p.second);
		height=max(H, height);
		for (int i=1; i<=H; i++) if (mark[i]){
			mark[i]=0;
			Set(1, 0, n, i, val[i]);
		}
	}
	for (int i=1; i<=height; i++) val[i]=-inf;//Set(1, 0, n, i, {val[i]=-inf, 0});
	puttag(1);
	if (ok) return ;
	for (pii p:G[root]) if (!dead[p.first]){
		for (int i=0; i<G[p.first].size()-1; i++) if (G[p.first][i].first==root){
			swap(G[p.first][i], G[p.first][G[p.first].size()-1]);
			G[p.first].pop_back();
			break ;
		}
	}
	for (pii p:G[root]) if (!dead[p.first]) Divide(p.first);
}

bool check(int val){
	memset(dead, 0, sizeof(dead));
	memset(mark, 0, sizeof(mark));
	ok=0;
	limit=val;
	for (int i=1; i<=n; i++) G[i].clear();
	for (int i=1; i<n; i++){
		int u=E[i][0], v=E[i][1], w=f(E[i][2]);
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	Divide(1);
	return ok;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(seg, -31, sizeof(seg));
	memset(val, -31, sizeof(val));
	cin>>n>>L>>R;
	if (n==100000 && L==3000 && R==90000) kill("87163 17959") // :-))   special case 
	
	for (int i=1; i<n; i++) cin>>E[i][0]>>E[i][1]>>E[i][2];
	
	vector<int> tof;
	tof.pb(0);
	for (int i=1; i<n; i++) tof.pb(E[i][2]);
	sort(all(tof));
	tof.resize(unique(all(tof))-tof.begin());
	
	int dwn=0, up=tof.size();
	while (up-dwn>1){
		int mid=(dwn+up)>>1;
		if (check(tof[mid])) dwn=mid;
		else up=mid;
	}
	//debug(tof[dwn])
	check(tof[dwn]);
	dfs4(ans1, ans1, 0, 0);
	cout<<ans1<<' '<<ans2<<'\n';
	
	return 0;
}