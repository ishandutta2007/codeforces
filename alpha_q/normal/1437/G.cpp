#include <bits/stdc++.h>

using namespace std;

const int MAX = 300010;

int maxVal[MAX];

struct AC {
  int N, P;
  const int A = 26;
  vector <vector <int>> next;
  vector <int> link, out_link;
  vector <vector <int>> out;
  
  AC(): N(0), P(0) {node();}
  
  int node() {
    next.emplace_back(A, 0);
    link.emplace_back(0);
    out_link.emplace_back(0);
    out.emplace_back(0);
    return N++;
  }

  inline int get (char c) {
    return c - 'a';
  }

  int add_pattern (const string T) {
    int u = 0;
    for (auto c : T) {
      if (!next[u][get(c)]) next[u][get(c)] = node();
      u = next[u][get(c)];
    }
    out[u].push_back(P);
    return P++;
  }

  void compute() {
    queue <int> q;
    for (q.push(0); !q.empty();) {
      int u = q.front(); q.pop();
      for (int c = 0; c < A; ++c) {
        int v = next[u][c];
        if (!v) next[u][c] = next[link[u]][c];
        else {
          link[v] = u ? next[link[u]][c] : 0;
          out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
          q.push(v);
        }
      }
    }
  }

  int advance (int u, char c) {
    while (u && !next[u][get(c)]) u = link[u];
    u = next[u][get(c)];
    return u;
  }

  int match (const string S) {
    int ret = -1, u = 0;
    for (auto c : S) {
      u = advance(u, c);
      for (int v = u; v; v = out_link[v]) {
        for (auto p : out[v]) ret = max(ret, maxVal[p]);
      }
    }
    return ret;
  }
};

AC aho;
map <string, int> to;
set <pair <int, int>> vals[MAX];
int n, m, id[MAX], ptr, who[MAX], now[MAX];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    if (to.find(s) == to.end()) {
      to[s] = ptr++;
      aho.add_pattern(s);
    }
    now[i] = 0, who[i] = to[s];
    vals[to[s]].emplace(0, i);
  }
  for (int i = 0; i < ptr; ++i) {
    maxVal[i] = 0;
  }
  aho.compute();
  while (m--) {
    int cmd; cin >> cmd;
    if (cmd == 1) {
      int pos, x;
      cin >> pos >> x; --pos;
      vals[who[pos]].erase(make_pair(now[pos], pos));
      now[pos] = x;
      vals[who[pos]].emplace(now[pos], pos);
      maxVal[who[pos]] = vals[who[pos]].rbegin() -> first;
      // for (int i = 0; i < ptr; ++i) cout << maxVal[i] << " "; cout << '\n';
    } else {
      string text; cin >> text;
      int ans = aho.match(text);
      cout << ans << '\n';
    }
  }
  return 0;
}