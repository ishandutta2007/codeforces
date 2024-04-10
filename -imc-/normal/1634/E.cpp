#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

struct edge {
  int u, v;
  int pos1, pos2;

  int colored;
  bool used = false;

  int other(int x) const {
    assert(x == u || x == v);
    return x == u ? v : u;
  }

  int pos(int x) const {
    return x == u ? pos1 : pos2;
  }
};

struct graph {
  vector<edge> e;
  vector<vector<int>> adj;
  vector<int> pos;

  void add_edge(int u, int v, int pos1, int pos2) {
    assert(pos1 != pos2);

    e.push_back(edge{u, v, pos1, pos2});
    adj[u].push_back(e.size() - 1);
    adj[v].push_back(e.size() - 1);
  }
};

void solve(bool read) {
  int n_arrays;
  cin >> n_arrays;

  map<int, pair<int, int>> last_meet;

  vector<vector<int>> a(n_arrays);

  graph g;
  g.adj.resize(n_arrays);

  int cur_pos = 0;
  for (int i = 0; i < n_arrays; ++i) {
    int n;
    cin >> n;
    a[i].resize(n);

    for (int& x : a[i]) {
      cin >> x;

      if (last_meet.count(x)) {
        g.add_edge(last_meet[x].first, i, last_meet[x].second, cur_pos);
        //cout << "edge " << last_meet[x].first << " " << i << "\n";

        int edge_num = g.e.size() - 1;

        last_meet.erase(x);
      } else {
        last_meet[x] = make_pair(i, cur_pos);
      }

      ++cur_pos;
    }
  }

  vector<char> ans(cur_pos, 'X');

  if (!last_meet.empty()) {
    cout << "NO\n";
    return;
  }

  int n = g.adj.size();
  g.pos.resize(n);

  bool flag = false;
  for (int i = 0; i < g.e.size(); ++i) {
    if (!g.e[i].used) {
      vector<pair<int, int>> st;

      g.e[i].used = true;
      st.emplace_back(g.e[i].u, i);

      while (!st.empty()) {
        int cur = st.back().first;

        bool found = false;

        while (g.pos[cur] < g.adj[cur].size()) {
          int e_index = g.adj[cur][g.pos[cur]];
          auto& ed = g.e[e_index];
          ++g.pos[cur];

          if (!ed.used) {
            ed.used = true;
            st.emplace_back(ed.other(cur), e_index);
            found = true;
            break;
          }
        }

        if (!found) {
          int e_index = st.back().second;
          //cout << "euler " << cur << " " << g.e[e_index].other(cur) << "\n";

          if (g.e[e_index].other(cur) != cur) {
            ans[g.e[e_index].pos(cur)] = 'L';
            ans[g.e[e_index].pos(g.e[e_index].other(cur))] = 'R';
          } else {
            ans[g.e[e_index].pos1] = 'L';
            ans[g.e[e_index].pos2] = 'R';
          }

          //cout << "pos " << g.e[e_index].pos(cur) << " " << g.e[e_index].pos(g.e[e_index].other(cur)) << "\n";

          g.e[e_index].colored = flag ? cur : g.e[e_index].other(cur);
          flag = !flag;
          st.pop_back();
        }
      }
    }
  }

  cout << "YES\n";
  cur_pos = 0;
  for (auto& arr : a) {
    for (auto it : arr) {
      cout << ans[cur_pos];
      ++cur_pos;
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  //cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //solve(false);

  return 0;
}