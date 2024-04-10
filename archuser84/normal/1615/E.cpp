///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#define int ll
#define pii pll

const int N = 200'010;
vector<int> A[N];
bool mark[N]={};
int st[N], ft[N], rvst[N];
int par[N];
ll n, k;

void dfs(int v, int p, int& t){
	par[v] = p;
	st[v] = t++;
	rvst[st[v]] = v;
	for(int u : A[v])
		if(u != p)
			dfs(u,v,t);
	ft[v] = t;
}

pii seg[N<<2];
int lzy[N<<2];

void tag(int i, int x){seg[i].first+=x; lzy[i]+=x;}
void ppg(int i){
	if(lzy[i]){
		tag(2*i+1, lzy[i]);
		tag(2*i+2, lzy[i]);
		lzy[i]=0;
	}
}

void init(int i=0, int b=0, int e=n){
	if(e-b == 1) {seg[i] = {0,b}; return;}
	init(2*i+1,b,(b+e)/2);
	init(2*i+2,(b+e)/2,e);
	seg[i] = {0,e-1};
}

void add(int l, int r, int x, int i=0, int b=0, int e=n){
	if(l <= b && e <= r) return tag(i,x);
	if(r <= b || e <= l) return;
	ppg(i);
	add(l,r,x,2*i+1,b,(b+e)/2);
	add(l,r,x,2*i+2,(b+e)/2,e);
	seg[i]=max(seg[2*i+1],seg[2*i+2]);
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k;
	Loop(i,1,n){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	dfs(0,-1,*new int(0));
	init();
	Loop(i,0,n) add(st[i], ft[i], 1);
	ll ans = -(n*n)/4;
	ll cntb = n, cntr=0;
	Loop(i,0,k){
		int v = rvst[seg[0].second];
		add(st[v], st[v]+1, -1);
		while(v != -1 && !mark[v]){
			mark[v] = 1;
			add(st[v], ft[v], -1);
			v = par[v];
			--cntb;
		}
		++cntr;
		if(cntb > n/2) ans = max(ans, cntr*(n-cntr) - n*n/4);
		else ans = max(ans, cntr*(n-cntr) - cntb*(n-cntb));
	}
	cout << ans << '\n';
}