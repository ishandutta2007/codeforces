#include <bits/stdc++.h>

using namespace std;

const int A = 14;

struct AC {
  int N, P;
  vector <vector <int>> next;
  vector <int> link, out_link;
  vector <vector <int>> out;
  
  AC() : N(0), P(0) {node();}
  
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
};

typedef long long ll;

const int M = 1010;
const ll INF = 1e16 + 5;

AC aho;
string text;
int k, nxt[M][A], jump[M][A];
ll cost[M], out[M], dp[1 << A][M], extra[M][A];

int main() {
  cin >> k;
  for (int i = 0; i < k; ++i) {
    string cur;
    cin >> cur >> cost[i];
    aho.add_pattern(cur);
  }
  aho.compute();
  for (int i = 0; i < aho.N; ++i) {
    for (int j = 0; j < A; ++j) nxt[i][j] = aho.advance(i, 'a' + j);
    for (int j = i; j; j = aho.out_link[j]) for (int x : aho.out[j]) out[i] += cost[x];
  }
  cin >> text;
  vector <int> dunnos;
  for (int i = 0; i < text.size(); ++i) {
    if (text[i] == '?') dunnos.emplace_back(i);
  }
  dunnos.emplace_back(text.size());
  for (int i = 0; i < aho.N; ++i) for (int j = 0; j + 1 < dunnos.size(); ++j) {
    jump[i][j] = i, extra[i][j] = out[i];
    for (int p = dunnos[j] + 1; p < dunnos[j + 1]; ++p) {
      jump[i][j] = nxt[jump[i][j]][text[p] - 'a'];
      extra[i][j] += out[jump[i][j]];
    }
  }
  for (int mask = (1 << A) - 1; mask >= 0; --mask) {
    for (int state = 0; state < aho.N; ++state) {
      int at = __builtin_popcount(mask);
      if (at >= dunnos.size() - 1) continue;
      dp[mask][state] = -INF;
      for (int here = 0; here < A; ++here) if (~mask & 1 << here) {
        int to = nxt[state][here];
        dp[mask][state] = max(dp[mask][state], extra[to][at] + dp[mask | 1 << here][jump[to][at]]);
      }
    }
  }
  ll ans = 0;
  int at = 0, state = 0;
  while (at < dunnos[0]) state = nxt[state][text[at++] - 'a'], ans += out[state];
  ans += dp[0][state];
  cout << ans << '\n'; 
  return 0;
}