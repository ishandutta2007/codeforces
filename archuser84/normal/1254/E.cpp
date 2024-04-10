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

const int mod = 1000000007;
const int N = 5e5 + 10;
vector<int> A[N];
int *in[N], *out[N];
int par[N], pariu[N], parid[N];
int dep[N];
int cnt[N];
ll fct[N];
int a[N];
int n;

void dfs(int v, int p, int h)
{
	par[v] = p; dep[v]=h;
	Loop(i,0,A[v].size())
		if(A[v][i] != p){
			dfs(A[v][i], v, h+1);
			parid[A[v][i]]=i;
		}
		else
			pariu[v]=i;
}

void add(int v, int i, int j){
	dbg("add",v,i,j);
	if(out[v][i] != -1) {dbg("contradiction in out",v); Kill(0);}
	if(in [v][j] != -1) {dbg("contradiction in in" ,v); Kill(0);}
	out[v][i] = j;
	in [v][j] = i;
	++cnt[v];
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,1,n){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	Loop(i,0,n){
		cin >> a[i];
		--a[i];
	}
	Loop(i,0,n)
		vdbg("A",i,":",A[i]);
	Loop(i,0,n){
		in[i] = new int[A[i].size()+2];
		memset(in[i],-1,4*A[i].size()+8);
		out[i] = new int[A[i].size()+2];
		memset(out[i],-1,4*A[i].size()+8);
	}
	dfs(0,-1,0);
	dbg("par :",vector<int>(par ,par +n));
	dbg("pariu:",vector<int>(pariu,pariu+n));
	dbg("parid:",vector<int>(parid,parid+n));
	dbg("dep :",vector<int>(dep ,dep +n));
	dbg("a   :",vector<int>(a   ,a   +n));
	int cnt = 0;
	Loop(i,0,n){
		if(a[i]==-1) continue;
		int v = i, u = a[i];
		dbg("limit",v,u);
		int vi = A[v].size(), ui = A[u].size()+1;
		while(dep[v] > dep[u]){
			add(v, vi, pariu[v]);
			vi = parid[v];
			v = par[v];
			++cnt;
		}
		while(dep[v] < dep[u]){
			add(u, pariu[u], ui);
			ui = parid[u];
			u = par[u];
			++cnt;
		}
		while(v != u){
			add(v, vi, pariu[v]);
			vi = parid[v];
			v = par[v];
			++cnt;
			add(u, pariu[u], ui);
			ui = parid[u];
			u = par[u];
			++cnt;
		}
		add(v, vi, ui);
		if(cnt > 2*n) {dbg("cnt too big"); Kill(0);}
	}
	dbg("cnt :",vector<int>(::cnt ,::cnt +n));
	Loop(i,0,n){
		int *vis = new int[A[i].size()+2];
		memset(vis,-1,4*A[i].size()+8);
		Loop(j,0,A[i].size()+2){
			if(vis[j]!=-1) continue;
			int k = j;
			while(k != -1){
				if(vis[k] == j) {dbg("cycle found in",i); Kill(0);}
				if(vis[k] != -1) break;
				vis[k] = j;
				k = out[i][k];
			}
		}
		int k = A[i].size();
		int cnt = 0;
		while(out[i][k] != -1)
			{++cnt; k = out[i][k];}
		if(k == A[i].size()+1 && cnt != A[i].size()+1)
			{dbg("start connected to end without all in",i); Kill(0);}
	}
	fct[0] = 1; Loop(i,1,n) fct[i] = (fct[i-1]*i) % mod;
	dbg("fct :",vector<int>(fct ,fct +n));
	ll ans = 1;
	Loop(i,0,n) if(::cnt[i]<A[i].size())
		ans = ans*fct[A[i].size()-::cnt[i]] % mod;
	cout << ans << '\n';
}