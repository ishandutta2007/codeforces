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
		str << "[";
		if(vec.size()){
			Loop(i,0,vec.size()-1)
				str << vec[i] << ", ";
			str << vec.back();
		}
		str << "]";
		return str;
	}
	template<class T, class U>
	ostream& operator<<(ostream& str, pair<T,U> p){
		return str << "(" << p.first << ", " << p.second << ")";
	}
	void _impl_dbg(){}
	template<class T, class... U> void _impl_dbg(T x, U... y){
		cout << x << ' ';
		_impl_dbg(y...);
	}
	template<class... T> int _dbg(T... x){
		cout << "dbg: ";
		_impl_dbg(x...);
		cout << endl;
		return 0;
	}
#ifdef DBG
#define dbg(...) dbgcrap::_dbg(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
}

const int N = 200'010;

namespace rmq
{
	vector<pii> a;
	pii b[20][2*N];
	int n;

	void build(){
		n = a.size();
		Loop(i,0,n) b[0][i] = a[i];
		for(int k = 0; k < 19; ++ k)
			for(int i = 0; i + (2<<k) <= n; ++i)
				b[k+1][i] = min(b[k][i], b[k][i+(1<<k)]);
	}

	pii get(int l, int r){
		int k = __lg(r-l);
		auto ans = min(b[k][l], b[k][r-(1<<k)]);
		dbg("rmq",l,r,"=",ans);
		return ans;
	}
}

vector<int> A[N];
vector<pii>  B[N];
int tim[N], dep[N];
int n;

void dfs(int v, int p, int d){
	dep[v] = d; tim[v] = rmq::a.size();
	rmq::a.emplace_back(d,v);
	for(int u : A[v]){
		if(u == p) continue;
		dfs(u,v,d+1);
		rmq::a.emplace_back(d,v);
	}
}

int lca(int v, int u){
	return rmq::get(min(tim[v],tim[u]), max(tim[v], tim[u])+1).second;
}

int vv[N], vs[N];
int imp[N];
struct obj{
	int dis, vi;
	bool operator<(const obj& x) const {
		int a = (  dis+vs[  vi]-1)/vs[  vi];
		int b = (x.dis+vs[x.vi]-1)/vs[x.vi];
		bool ans = a<b || (a==b && vi < x.vi);
		dbg("cmp:",dis,vi,"-",x.dis,x.vi,":",ans);
		return ans;
	}
} dis[N];

void addE(int v, int u){
	B[v].emplace_back(u, abs(dep[v]-dep[u]));
	B[u].emplace_back(v, abs(dep[v]-dep[u]));
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
	dfs(0,-1,0);
	rmq::build();
	dbg("rmq:",rmq::a);
	dbg("tim:",vector<int>(tim,tim+n));
	int q;
	cin >> q;
	while(q--){
		int k, m;
		cin >> k >> m;
		vector<pii> vec;
		Loop(i,0,k){
			cin >> vv[i] >> vs[i]; --vv[i];
			vec.push_back({tim[vv[i]], vv[i]});
		}
		Loop(i,0,m){
			cin >> imp[i]; --imp[i];
			vec.emplace_back(tim[imp[i]], imp[i]);
		}

		sort(vec.begin(), vec.end());
		int timp = vec.size();
		Loop(i,0,timp-1){
			int v = lca(vec[i].second, vec[i+1].second);
			vec.emplace_back(tim[v], v);
		}
		sort(vec.begin(), vec.end());
		vec.resize(unique(vec.begin(), vec.end()) - vec.begin());

		vector<int> st;
		st.push_back(vec[0].second);
		Loop(i,1,vec.size()){
			while(lca(st.back(), vec[i].second) != st.back()) {
				dbg("lca",st.back(),vec[i].second,"=",lca(st.back(), vec[i].second));
				st.pop_back();
			}
			addE(st.back(), vec[i].second);
			st.push_back(vec[i].second);
		}
		dbg("vec:",vec);
		Loop(i,0,n)
			dbg("B",i,":",B[i]);

		set<pair<obj,int>> s;
		for(auto [_,i] : vec) dis[i] = {N-1,N-1}; vs[N-1]=1;
		Loop(i,0,k) {
			dis[vv[i]] = {0,(int)i};
			s.emplace(dis[vv[i]], vv[i]);
		}
		while(s.size()){
			auto [d, v] = *s.begin(); s.erase(s.begin());
			dbg("dij on",v);
			for(auto [u, w] : B[v]){
				d.dis += w;
				dbg(v,"->",u);
				if(d < dis[u]){
					s.erase ({dis[u],u});
					dis[u] = d;
					s.insert({dis[u],u});
				}
				d.dis -= w;
			}
		}

		for(auto [_,i] : vec) B[i].clear();

		Loop(i,0,m) cout << dis[imp[i]].vi+1 << ' ';
		cout << '\n';
	}
}