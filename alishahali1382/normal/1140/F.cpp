#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 300010, LOG=20;

struct DSU{
	int sz1[MAXN*2], sz2[MAXN*2];
	int par[MAXN*2];
	stack<pair<int*, int>> stk;
	DSU(){
		for (int i=1; i<MAXN; i++) sz1[i]=sz2[MAXN+i]=1;
		for (int i=1; i<2*MAXN; i++) par[i]=i;
	}
	void set_par(int x, int y){
		stk.push({par+x, par[x]});
		stk.push({sz1+y, sz1[y]});
		stk.push({sz2+y, sz2[y]});
		par[x]=y;
		sz1[y]+=sz1[x];
		sz2[y]+=sz2[x];
	}
	int get(int x){
		if (par[x]==x) return x;
		return get(par[x]);
	}
	int join(int x, int y){
		x=get(x);
		y=get(y);
		if (x==y) return 0;
		if (sz1[x]+sz2[x]>sz1[y]+sz2[y]) swap(x, y);
		set_par(x, y);
		return 1;
	}
	void undo(){
		for (int i=0; i<3; i++){
			(*stk.top().first)=stk.top().second;
			stk.pop();
		}
	}
	ll query(int x){
		x=get(x);
		return 1ll*sz1[x]*sz2[x];
	}
} dsu;

ll n, m, k, u, v, x, y, cnt, a, b, ans;
ll out[MAXN];
map<pii, int> Tin;
set<pii> points;
vector<pii> seg[MAXN<<2];

void add(int id, int tl, int tr, int l, int r, pii E){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r){
		seg[id].pb(E);
		return ;
	}
	int mid=(tl+tr)>>1;
	add(id<<1, tl, mid, l, r, E);
	add(id<<1 | 1, mid+1, tr, l, r, E);
}

void dfs(int id, int tl, int tr){
	ll last_ans=ans, t=0;
	//debug(id)
	//debug2(tl, tr)
	for (pii p:seg[id]){
		ans-=dsu.query(p.first)+dsu.query(p.second);
		int res=dsu.join(p.first, p.second);
		t+=res;
		ans+=dsu.query(p.first)*(2-res);
		//debugp(p)
	}
	if (tl==tr) cout<<ans<<' ';
	else{
		int mid=(tl+tr)>>1;
		dfs(id<<1, tl, mid);
		dfs(id<<1 | 1, mid+1, tr);
	}
	
	while (t--) dsu.undo();
	ans=last_ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>x>>y;
		y+=MAXN;
		if (Tin.count({x, y})){
			add(1, 1, n, Tin[{x, y}], i-1, {x, y});
			Tin.erase({x, y});
		}
		else Tin[{x, y}]=i;
	}
	for (auto it:Tin) add(1, 1, n, it.second, n, it.first);
	dfs(1, 1, n);
	
	return 0;
}