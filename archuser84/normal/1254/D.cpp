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

namespace dbgcrap{
	template<class T>
	ostream& operator<<(ostream& str, vector<T> vec){
		str << "(";
		if(vec.size()){
			Loop(i,0,vec.size()-1)
				str << vec[i] << ", ";
			str << vec.back();
		}
		str << ")";
		return str;
	}
	void _impl_dbg(){}
	template<class T, class... U> void _impl_dbg(T x, U... y){
		cout << x << ' ';
		_impl_dbg(y...);
	}
	template<class... T> void _dbg(T... x){
		cout << "dbg: ";
		_impl_dbg(x...);
		cout << '\n';
	}
	template<class... T> void _vdbg(T... x){
		cout << "vdbg: ";
		_impl_dbg(x...);
		cout << '\n';
	}
#if defined DBG || defined VRB
#define dbg(...) dbgcrap::_dbg(__VA_ARGS__)
#else
#define dbg(...) NULL
#endif
#ifdef VRB
#define vdbg(...) dbgcrap::_vdbg(__VA_ARGS__)
#else
#define vdbg(...) NULL
#endif
}

#define int ll

const int mod = 998244353;
const int N = 150'010;

ll mpow(ll x, ll y){ll ans = 1;while(y){if(y&1)ans = ans*x %mod;x = x*x%mod;y >>= 1;}return ans;}

struct fen_ru{
	int* a; int n;
	void add(int r, int x){
		while(r){
			a[r] = (a[r]+x)%mod;
			r -= r&-r;
		}
	}
	int get(int i){
		//vdbg("fen_ru: getting",i,"with n =",n);
		++i;
		int ans = 0;
		while(i <= n){
			ans = (ans+a[i])%mod;
			i += i&-i;
		}
		return ans;
	}
	void add(int l, int r, int x){add(r,x);add(l,mod-x);}
	void init(int x){a=new int[x+1]; memset(a,0,sizeof(a[0])*(x+1)); n=x;}
};
struct fen_pu{
	int* a; int n;
	int get(int r){
		int ans=0;
		while(r){
			ans = (a[r]+ans)%mod;
			r -= r&-r;
		}
		return ans;
	}
	void add(int i, int x){
		++i;
		while(i <= n){
			a[i] = (a[i]+x)%mod;
			i += i&-i;
		}
	}
	int get(int l, int r){return (get(r)+mod-get(l))%mod;}
	void init(int x){a=new int[x+1]; memset(a,0,sizeof(a[0])*(x+1)); n=x;}
};

int Add[N];
vector<int> A[N];
int st[N], ft[N];
int par[N];
int depth[N];
int hchild[N], hroot[N], hcnt[N];
fen_pu hfen[N];
fen_ru fen;
int n, inv_n;

void dfs1(int v, int p, int& t){ // st & ft
	vdbg("dfs1 on",v);
	st[v] = t++;
	for(int u : A[v])
		if(u != p)
			dfs1(u, v, t);
	ft[v] = t;
}
inline static int sz(int v){return ft[v]-v;}
void dfs2(int v, int p, int d){ // par & hchild & depth
	vdbg("dfs2 on",v);
	par[v] = p;
	hchild[v] = -1;
	depth[v] = d;
	for(int u : A[v])
		if(u != p){
			dfs2(u, v, d+1);
			if(hchild[v] == -1 || sz(hchild[v]) < sz(u))
				hchild[v] = u;
		}
	vdbg("hchild",v,"=",hchild[v]);
}
void dfs3(int v, int hrt){ // hroot & hcnt
	vdbg("dfs3 on",v);
	hcnt[hrt]++;
	hroot[v] = hrt;
	for(int u : A[v])
		if(u != par[v])
			dfs3(u, u==hchild[v]?hrt:u);
}

template<class T>
void replace(T *x){ // replaces x with starting times
	static T tmp[N];
	Loop(i,0,n) tmp[st[i]] = x[i];
	Loop(i,0,n) x[i] = tmp[i];
}

signed main(){
	cin.tie(0) -> sync_with_stdio(false);
	int q;
	cin >> n >> q; inv_n = mpow(n, mod-2);
	dbg("inv n =",inv_n);
	Loop(i,1,n){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	dfs1(0, 0, *new int(0));
	Loop(i,0,n){
		for(int& x : A[i])
			x = st[x];
		sort(A[i].begin(), A[i].end());
	}
	replace(A);
	replace(ft);
	dbg("st:",vector<int>(st,st+n));
	dbg("ft:",vector<int>(ft,ft+n));
	Loop(i,0,n)
		vdbg("A",i,":",A[i]);
	dfs2(0,-1,0);
	dfs3(0,0);
	Loop(i,0,n) if(hroot[i]==i){
		hfen[i].init(hcnt[i]);
		vdbg(i,"has hcnt of",hcnt[i]);
	}

	dbg("hchild:",vector<int>(hchild,hchild+n));
	dbg("hroot :",vector<int>(hroot ,hroot +n));
	dbg("hcnt  :",vector<int>(hcnt  ,hcnt  +n));
	dbg("par   :",vector<int>(par   ,par   +n));
	dbg("depth :",vector<int>(depth ,depth +n));

	fen.init(n);

	while(q--){
		int t, v, d;
		cin >> t >> v; v = st[v-1];
		dbg("v is",v);
		if(t==1){
			cin >> d;
			int rt = hroot[v];
			int i = depth[v]-depth[rt];
			Add[v] = (Add[v]+d)%mod;
			dbg("hfen: adding",d,"to",v,"which is at distance",i,"from",rt);
			hfen[rt].add(i, d*(n-sz(hchild[v]))%mod);
			dbg("calling fen");
			fen.add(0,v,d*sz(v)%mod);
			fen.add(ft[v],n,d*sz(v)%mod);
		} else { // and = fen.get(v) + hld
			int ans = fen.get(v);
			dbg(v,"has",ans,"from non-ancestors");
			dbg("The worst part is happening now:");
			ans = (ans + Add[v]*n)%mod;
			dbg("ans became",ans,"after getting from v");
			int lst = v;
			v = par[v];
			while(v != -1){
				if(lst == hchild[v]){
					int rt = hroot[v];
					int i = depth[v]-depth[rt];
					dbg("getting from",rt,"to",v,"(inclusive) which is at distance",i);
					ans = (ans+hfen[rt].get(i+1))%mod;
					dbg("ans became",ans);
					v = par[rt];
					lst = rt;
				} else {
					dbg("getting fron non-heavy parent",v,"which has",Add[v]);
					ans = (ans + (n-sz(lst))*Add[v]) % mod;
					dbg("ans became",ans);
					lst = v;
					v = par[v];
				}
			}
			dbg("final ans:", ans);
			cout << (ll)ans*inv_n%mod << '\n';
		}
	}
}