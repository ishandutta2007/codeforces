// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


struct MCMF { 
	#define f first
	#define s second
	#define sz(x) ll(x.size())
	using F = ll; using C = ll; // flow type, cost type
	struct Edge { int to; F flo, cap; C cost; };
	typedef vector<int> vi;
	int N; vector<C> p, dist; vi pre; vector<Edge> eds; vector<vi> adj;
	void init(int _N) { N = _N;
		p.resize(N), dist.resize(N), pre.resize(N), adj.resize(N); }
	void ae(int u, int v, F cap, C cost) { assert(cap >= 0); 
		adj[u].pb(eds.size()); eds.pb({v,0,cap,cost}); 
		adj[v].pb(eds.size()); eds.pb({u,0,0,-cost});
	} // use asserts, don't try smth dumb
	bool path(int s, int t) { // find lowest cost path to send flow through
		const C inf = numeric_limits<C>::max(); for(int i = 0 ; i < N ; i++) dist[i] = inf;
		using T = pair<C,int>; priority_queue<T,vector<T>,greater<T>> todo; 
		todo.push({dist[s] = 0,s}); 
		while (sz(todo)) { // Dijkstra
			T x = todo.top(); todo.pop(); if (x.f > dist[x.s]) continue;
			for(auto &e:adj[x.s]) { const Edge& E = eds[e]; // all weights should be non-negative
				if (E.flo < E.cap && dist[E.to] > x.f+E.cost+p[x.s]-p[E.to]){
					dist[E.to] = x.f+E.cost+p[x.s]-p[E.to];
					pre[E.to] = e, todo.push({dist[E.to],E.to});
				}
			}
		} // if costs are doubles, add some EPS so you 
		// don't traverse ~0-weight cycle repeatedly
		return dist[t] != inf; // return flow
	}
	ll calc(int s, int t, ll _k) { assert(s != t);
		for(int _ = 0 ; _ < N ; _++) for(int e = 0 ; e < sz(eds) ; e++) { const Edge& E = eds[e]; // Bellman-Ford
			if (E.cap) p[E.to]=min(p[E.to],p[eds[e^1].to]+E.cost); }
		F totFlow = 0; C totCost = 0;
		ll ans = 0;
		while (path(s,t)) { // p -> potentials for Dijkstra
			for(int i = 0 ; i < N ; i++) p[i] += dist[i]; // don't matter for unreachable nodes
			F df = numeric_limits<F>::max();
			for (int x = t; x != s; x = eds[pre[x]^1].to) {
				const Edge& E = eds[pre[x]]; df=min(df,E.cap-E.flo); }
			

			if(p[t] - p[s] > 0)
				df = min(df, (_k - totCost) / (p[t] - p[s]));

			totFlow += df; totCost += (p[t]-p[s])*df;
			if(df == 0) break;
			if(totCost <= _k) ans = totFlow;
			for (int x = t; x != s; x = eds[pre[x]^1].to)
				eds[pre[x]].flo += df, eds[pre[x]^1].flo -= df;
		} // get max flow you can send along path
		return ans;
	}
} flow;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	flow.init(n + 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int c;
			cin >> c;
			if(c){
				flow.ae(i, j, c, 0);
				flow.ae(i, j, k, 1);
			}
		}
	}
	cout << flow.calc(1, n, k) << '\n';
	return 0;
}