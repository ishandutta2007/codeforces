#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

const Flow inf = 1e9;

struct PushRelabel {
	vector<vector<Edge>> g;
	vector<Flow> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
}; 

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> m >> m;
	if(m == 0){
		cout << 0 << endl;
		return 0;
	}

	vector<pii> lo(m), hi(m);

	rep(i,0,m) cin >> lo[i].first >> lo[i].second
		       >> hi[i].first >> hi[i].second;
	trav(pa, hi) ++pa.first, ++pa.second;

	map<int,int> xren, yren;
	trav(pa, lo) xren[pa.first], yren[pa.second];
	trav(pa, hi) xren[pa.first], yren[pa.second];
	int ixx = 0, ixy = 0;
	trav(pa, xren) pa.second = ixx++;
	trav(pa, yren) pa.second = ixy++;
	--ixx, --ixy;
	vi xlen(ixx), ylen(ixy);
	int prev = 0;
	trav(pa, xren){
		if(prev) xlen[pa.second-1] = pa.first - prev;
		prev = pa.first;
	}
	prev = 0;
	trav(pa, yren){
		if(prev) ylen[pa.second-1] = pa.first - prev;
		prev = pa.first;
	}
	trav(pa, lo){
		pa.first = xren[pa.first];
		pa.second = yren[pa.second];
	}
	trav(pa, hi){
		pa.first = xren[pa.first];
		pa.second = yren[pa.second];
	}
	vector<vector<bool>> black(ixx, vector<bool>(ixy, false));
	rep(i,0,m){
		rep(x,lo[i].first,hi[i].first)
			rep(y,lo[i].second,hi[i].second)
				black[x][y] = true;
	}

	PushRelabel pr(ixx + ixy + 2);		
	int s = ixx+ixy, t = s+1;
	rep(x,0,ixx) rep(y,0,ixy) if(black[x][y])
		pr.add_edge(x, y+ixx, inf);
	rep(x,0,ixx) pr.add_edge(s, x, xlen[x]);
	rep(y,0,ixy) pr.add_edge(y+ixx, t, ylen[y]);
	cout << pr.maxflow(s,t) << endl;
}