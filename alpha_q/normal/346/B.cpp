#include <bits/stdc++.h>

using namespace std;

const int A = 26;

struct AC {
  int N, P;
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
    return c - 'A';
  }

  int add_pattern (const string T) {
    int u = 0;
    for (int i = 0; i < T.size(); ++i) {
      char c = T[i];
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

  void match (const string S) {
    int u = 0;
    for (int i = 0; i < S.size(); ++i) {
      char c = S[i];
      u = advance(u, c);
      for (int v = u; v; v = out_link[v]) {
        for (auto p : out[v]) cout << p << endl;
      }
    }
  }
};

const int N = 105;

AC aho;
int n, m, k;
int nxt[N][A];
int f[N][N][N];
string s, t, p;
int par[N][N][N][3];

int main() {
  cin >> s >> t >> p;
  aho.add_pattern(p); aho.compute();
  n = s.size(), m = t.size(), k = p.size();
  for (int i = 0; i < aho.N; ++i) {
    for (int j = 0; j < A; ++j) {
      nxt[i][j] = aho.advance(i, j + 'A');
    }
  }
  for (int i = n; i > 0; --i) {
    for (int j = m; j > 0; --j) {
      for (int l = k - 1; l >= 0; --l) {
        int &cur = f[i][j][l];
        par[i][j][l][0] = i + 1, par[i][j][l][1] = j, par[i][j][l][2] = l;
        if (f[i + 1][j][l] > cur) {
          cur = f[i + 1][j][l];
          par[i][j][l][0] = i + 1, par[i][j][l][1] = j, par[i][j][l][2] = l;
        }
        if (f[i][j + 1][l] > cur) {
          cur = f[i][j + 1][l];
          par[i][j][l][0] = i, par[i][j][l][1] = j + 1, par[i][j][l][2] = l;  
        }
        if (s[i - 1] == t[j - 1]) {
          if (p[l] != s[i - 1]) {
            int u = nxt[l][s[i - 1] - 'A'];
            if (1 + f[i + 1][j + 1][u] > cur) {
              cur = 1 + f[i + 1][j + 1][u];
              par[i][j][l][0] = i + 1, par[i][j][l][1] = j + 1, par[i][j][l][2] = u;
            }
          } else {
            if (l != k - 1) {
              if (1 + f[i + 1][j + 1][l + 1] > cur) {
                cur = 1 + f[i + 1][j + 1][l + 1];
                par[i][j][l][0] = i + 1, par[i][j][l][1] = j + 1, par[i][j][l][2] = l + 1;
              } 
            }
          }
        }
      }
    }
  }
  string ret = "";
  int x = 1, y = 1, match = 0;
  while (x <= n and y <= m) {
    if (par[x][y][match][0] == x + 1 and par[x][y][match][1] == y + 1) {
      ret += s[x - 1];
    }
    int _x = par[x][y][match][0], _y = par[x][y][match][1], _match = par[x][y][match][2];
    x = _x, y = _y, match = _match;
  }
  if (ret.empty()) cout << "0\n";
  else cout << ret << '\n';
  return 0;
}