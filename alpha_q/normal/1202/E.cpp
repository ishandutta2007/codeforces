#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 200010;

struct AC {
  int N, P;
  const int A = 26;
  vector <ll> size;
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
    size.resize(N, 0);
    for (q.push(0); !q.empty();) {
      int u = q.front(); q.pop();
      for (int c = 0; c < A; ++c) {
        int v = next[u][c];
        if (!v) next[u][c] = next[link[u]][c];
        else {
          link[v] = u ? next[link[u]][c] : 0;
          out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
          q.push(v);
          size[v] = out[v].size() + size[out_link[v]];
        }
      }
    }
  }

  int advance (int u, char c) {
    while (u && !next[u][get(c)]) u = link[u];
    u = next[u][get(c)];
    return u;
  }

  void match (const string S, vector <ll> &dp) {
    int u = 0;
    for (int i = 0; i < S.size(); ++i) {
      char c = S[i];
      u = advance(u, c);
      dp[i] = size[u];
    }
  }
};

int n;
string s, t;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  AC forw, bacw;
  cin >> t >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s; 
    forw.add_pattern(s);
    reverse(s.begin(), s.end());
    bacw.add_pattern(s);
  }
  int m = t.size();
  vector <ll> en(m, 0), st(m, 0);
  forw.compute();
  bacw.compute();
  forw.match(t, en);
  reverse(t.begin(), t.end());
  bacw.match(t, st);
  reverse(st.begin(), st.end());
  ll ans = 0;
  for (int i = 0; i + 1 < m; ++i) {
    ans += en[i] * 1LL * st[i + 1];
  }
  cout << ans << '\n';
  return 0;
}