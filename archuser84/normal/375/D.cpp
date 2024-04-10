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
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
const int N = 200'010;

struct obj
{
	map<int,int> mp;
	oset s;

	void add(int clr, int cnt){
		auto& x = mp[clr];
		if(x) s.erase(s.upper_bound(x));
		x += cnt;
		s.insert(x);
	}

	void add(obj* x){
		for(auto [a, b] : x->mp) add(a, b);
	}

	int get(int k){
		return s.size()-s.order_of_key(k);
	}

	size_t size(){return mp.size();}
};

int ans[N];
vector<int> A[N];
vector<pii> Q[N];
int c[N];
int n, m;

obj* dfs(int v, int p){
	obj* ans = new obj;
	ans->add(c[v], 1);
	for(int u : A[v]){
		if(u == p) continue;
		auto tmp = dfs(u, v);
		if(ans->size() < tmp->size()) swap(ans, tmp);
		ans->add(tmp);
	}
	for(auto [k, i] : Q[v])
		::ans[i] = ans->get(k);
	return ans;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop(i,0,n) cin >> c[i];
	Loop(i,1,n){
		int v, u;
		cin >> v >> u; --v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	Loop(i,0,m){
		int v, k;
		cin >> v >> k;
		Q[v-1].push_back({k, i});
	}
	dfs(0, -1);
	Loop(i,0,m) cout << ans[i] << '\n';
}