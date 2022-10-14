#include <bits/extc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;
 
struct MCMF {
	int N;
	vector<vi> ed, red;
	vector<VL> cap, flow, cost;
	vi seen;
	VL dist, pi;
	vector<pii> par;
 
	MCMF(int N) :
		N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}
 
	void add_edge(int from, int to, ll cap, ll cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}
 
	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;
 
		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});
 
		auto relax = [&](int i, ll cap, ll cost, int dir) {
			ll val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};
 
		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (int i : ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			for (int i : red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}
 
	pair<ll, ll> runFlow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
		rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
		return {totcost, totflow};
	}
 
	void setpi(int s) {
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
				for (int to : ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0);
	}
};
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector <int> cnt(26, 0);
    for (char &c : s) cnt[c - 'a']++;
    MCMF mcmf(n / 2 + 28);
    vector <int> cost(n);
    for (int i = 0; i < n; ++i) cin >> cost[i];
    for (int c = 0; c < 26; ++c) mcmf.add_edge(n / 2 + 26, c, cnt[c], 0);
    for (int i = 0; i < n / 2; ++i) {
        for (int c = 0; c < 26; ++c) {
            int j = n - 1 - i;
            mcmf.add_edge(c, i + 26, 1, -max((s[i] == 'a' + c ? cost[i] : 0), (s[j] == 'a' + c ? cost[j] : 0)));
        }
    }
    for (int i = 0; i < n / 2; ++i) mcmf.add_edge(i + 26, n / 2 + 27, 2, 0);
    mcmf.setpi(n / 2 + 26);
    pair <ll, ll> ans = mcmf.runFlow(n / 2 + 26, n / 2 + 27);
    assert(ans.second == n);
    cout << -ans.first << endl;
}