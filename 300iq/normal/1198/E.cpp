#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

struct rect {
  int x1, y1, x2, y2;
};

const int INF = 1000000000 + 7;
 
struct Edge {
    int a, b, cap, flow;
};

struct MaxFlow {
    int n, s, t;
    vector<int> d, ptr, q;
    vector< Edge > e;
    vector< vector<int> > g;

    MaxFlow(int n) : n(n), d(n), ptr(n), q(n), g(n) {
        e.clear();
        REP(i,n) {
            g[i].clear();
            ptr[i] = 0;
        }
    }

    void addEdge(int a, int b, int cap) {
        Edge e1 = { a, b, cap, 0 };
        Edge e2 = { b, a, 0, 0 };
        g[a].push_back( (int) e.size() );
        e.push_back(e1);
        g[b].push_back( (int) e.size() );
        e.push_back(e2);
    }
    int getMaxFlow(int _s, int _t) {
        s = _s; t = _t;
        int flow = 0;
        for (;;) {
            if (!bfs()) break;
            REP(i,n) ptr[i] = 0;
            while (int pushed = dfs(s, INF))
                flow += pushed;
        }
        return flow;
    }

private:
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        REP(i,n) d[i] = -1;
        d[s] = 0;

        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            REP(i,g[v].size()) {
                int id = g[v][i], to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs (int v, int flow) {
        if (!flow) return 0;
        if (v == t) return flow;
        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                to = e[id].b;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
};

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <rect> e;
  vector <int> rs, cs;
  for (int i = 0; i < m; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    e.push_back({x1, y1, x2, y2});
    rs.push_back(x1), rs.push_back(x2 + 1);
    cs.push_back(y1), cs.push_back(y2 + 1);
  }
  sort(rs.begin(), rs.end());
  rs.resize(unique(rs.begin(), rs.end()) - rs.begin());
  sort(cs.begin(), cs.end());
  cs.resize(unique(cs.begin(), cs.end()) - cs.begin());
  int s = rs.size() + cs.size();
  int t = rs.size() + cs.size() + 1;
  MaxFlow ans(t + 1);
  for (int i = 0; i + 1 < (int) rs.size(); i++) {
    ans.addEdge(s, i, rs[i + 1] - rs[i]);
  }
  for (int i = 0; i + 1 < (int) cs.size(); i++) {
    ans.addEdge(i + rs.size(), t, cs[i + 1] - cs[i]);
  }
  for (auto c : e) {
    for (int i = 0; i + 1 < (int) rs.size(); i++) {
      if (c.x1 <= rs[i] && rs[i + 1] - 1 <= c.x2) {
        for (int j = 0; j + 1 < (int) cs.size(); j++) {
          if (c.y1 <= cs[j] && cs[j + 1] - 1 <= c.y2) {
            ans.addEdge(i, rs.size() + j, INF);
          }
        }
      }
    }
  }
  cout << ans.getMaxFlow(s, t) << '\n';
}