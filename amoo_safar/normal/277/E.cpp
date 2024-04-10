#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 2e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;


// All Costs should be positive
template<typename F, typename C> // F = flow, C = cost
struct MinCostMaxFlow {
	struct Edge {
		int to;
		F cap;
		C cost;
		int id;
		Edge () : to(), cap(), cost(), id() {}
		Edge (int _to, F _cap, C _cost, int _id) : to(_to), cap(_cap), cost(_cost), id(_id) {}
	};
	int n;
	vector< Edge > E;
	vector< vector<int> > G;
	vector< int > par, use;
	vector< C > dis, pot;

	MinCostMaxFlow(int _n) : n(_n), use(_n, 0), pot(_n, 0){
		G.resize(_n);
		dis.resize(_n);
		par.resize(_n);
	}
	void AddEdge(int u, int v, F cap, C cost, int id = -1){
		G[u].push_back((int) E.size());
		E.push_back({v, cap, cost, id});
		G[v].push_back((int) E.size());
		E.push_back({u, 0, -cost, id});
	}
	pair<F, C> Push(int src, int snk){
		fill(dis.begin(), dis.end(), numeric_limits<C>::max());
		fill(par.begin(), par.end(), -1);
		fill(use.begin(), use.end(), 0);
		priority_queue<pair<C, int>, vector< pair<C, int> >, greater< pair<C, int> > > pq;
		dis[src] = 0; pq.push({dis[src], src});

		int fr;
		while(!pq.empty()){
			fr = pq.top().S; pq.pop();
			if(use[fr]) continue;
			use[fr] = 1;
			for(auto id : G[fr]){
				if(E[id].cap == 0) continue;
				C w = E[id].cost + pot[fr] - pot[E[id].to];
				if(dis[ E[id].to ] > dis[fr] + w){
					dis[ E[id].to ] = dis[fr] + w;
					pq.push({dis[ E[id].to ], E[id].to});
					par[ E[id].to ] = id;
				}
			}
		}

		if(use[snk] == 0) return {0, 0};

		for(int i = 0; i < n; i++) pot[i] += dis[i];
		F mn = numeric_limits<F>::max();
		for(int u = snk; ~par[u]; u = E[par[u] ^ 1].to) mn = min(mn, E[par[u]].cap);
		for(int u = snk; ~par[u]; u = E[par[u] ^ 1].to) E[par[u]].cap -= mn, E[par[u]^1].cap += mn;
		return {mn, pot[snk]};
	}

	pair<F, C> MinCost(int src, int snk){
		pair<F, C> res, tot = {0, 0};
		while((res = Push(src, snk)).F > 0){
			tot.S += res.F * res.S;
			tot.F += res.F;
		}
		return tot;
	}
};
template<typename F, typename C>
using Flow = MinCostMaxFlow<F, C>;


int x[N], y[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int src = 2 * n, snk = 2*n + 1;
	Flow<int, ld> flow(n + n + 2);

	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	int root = 0;
	for(int i = 0; i < n; i++) if(y[i] > y[root]) root = i;

	for(int i = 0; i < n; i++)
		flow.AddEdge(src, 2 * i, 2, 0);
	for(int i = 0; i < n; i++)
		if(i != root)
			flow.AddEdge(2 * i + 1, snk, 1, 0);
	function<ld(int, int)> dis = [&](int i, int j){
		return sqrt(static_cast<long double>( (y[i] - y[j]) * (y[i] - y[j]) + (x[i] - x[j]) * (x[i] - x[j])) );
	};

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(y[i] > y[j])
				flow.AddEdge(2 * i, 2 * j + 1, 1, dis(i, j));
	auto res = flow.MinCost(src, snk);
	cout << fixed << setprecision(16) << (res.F < n - 1 ? -1 : res.S) << '\n';
	return 0;
}