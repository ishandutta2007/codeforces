///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 300'010;
int par[2*N], val[2*N];
int L[2*N], R[2*N];
int n, n2;

int rt(int v){return par[v]==-1?v:par[v]=rt(par[v]);}
void unite(int v, int u, int e){
	v = rt(v);
	u = rt(u);
	par[u] = n+n2;
	par[v] = n+n2;
	L[n+n2] = v; R[n+n2] = u;
	val[n+n2] = e;
	++n2;
}

vector<int> vec;
int ord[N];

void dfs(int v){
	if(v<n) {ord[v] = vec.size(); return;}
	dfs(L[v]);
	vec.push_back(val[v]);
	dfs(R[v]);
}

const int lg = 20;
int rmq[lg][N];

void initrmq(){
	int n = vec.size();
	Loop(i,0,n) rmq[0][i] = vec[i];
	Loop(k,0,lg-1) for(int i=0; i+(2<<k)<=n; ++i)
		rmq[k+1][i] = max(rmq[k][i], rmq[k][i+(1<<k)]);
}
int getrmq(int l, int r){
	int k = __lg(r-l);
	return max(rmq[k][l], rmq[k][r-(1<<k)]);
}

struct node{
	int mn, mx;
	int tmn, tmx;
	int lzy;
} seg[N<<2];

static void tag(int i, bool b){
	seg[i].mn = b? seg[i].tmn: N;
	seg[i].mx = b? seg[i].tmx: -1;
	seg[i].lzy  = b;
}

static void ppg(int i){
	if(~seg[i].lzy){
		tag(2*i+1, seg[i].lzy);
		tag(2*i+2, seg[i].lzy);
		seg[i].lzy=-1;
	}
}

static void merge(int i){
	seg[i].mn = min(seg[2*i+1].mn, seg[2*i+2].mn);
	seg[i].mx = max(seg[2*i+1].mx, seg[2*i+2].mx);
}

void build(int i=0, int b=0, int e=n){
	if(e-b==1){seg[i]={N,-1,ord[b],ord[b],-1};return;}
	build(2*i+1,b,(b+e)/2);
	build(2*i+2,(b+e)/2,e);
	merge(i);
	seg[i].tmn = min(seg[2*i+1].tmn, seg[2*i+2].tmn);
	seg[i].tmx = max(seg[2*i+1].tmx, seg[2*i+2].tmx);
	seg[i].lzy=-1;
}

void up(int l, int r, bool bl, int i=0, int b=0, int e=n){
	if(l<=b&&e<=r) return tag(i,bl);
	if(r<=b||e<=l) return;
	ppg(i);
	up(l,r,bl,2*i+1,b,(b+e)/2);
	up(l,r,bl,2*i+2,(b+e)/2,e);
	merge(i);
}

pair<int,pii> E[N];

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	memset(par,-1,sizeof par);
	int q;
	cin >> n >> q;
	Loop(i,0,n-1){
		int v, u, w;
		cin >> v >> u >> w;
		--v; --u;
		E[i] = {w, {v,u}};
	}
	sort(E,E+n-1);
	Loop(i,0,n-1){
		auto [v, u] = E[i].second;
		unite(v,u,E[i].first);
	}
	dfs(rt(0));
	initrmq();
	build();
	while(q--){
		int t;
		cin >> t;
		if(t<3){
			int l, r;
			cin >> l >> r; --l;
			up(l, r, 2-t);
		} else {
			int v; cin >> v; --v;
			int mn=seg[0].mn, mx = seg[0].mx;
			int ans = -1;
			if(mn < ord[v]) ans = max(ans, getrmq(mn, ord[v]));
			if(mx > ord[v]) ans = max(ans, getrmq(ord[v], mx));
			cout << ans << '\n';
		}
	}
}