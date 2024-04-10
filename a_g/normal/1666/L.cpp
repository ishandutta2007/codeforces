#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int K = 20;
vector<int> G[N];
int second[N];
int par[N];
//int par[N][K];
//int dist[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, s;
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
  }

  vector<int> que(1, s);
  for (int v: G[s]) {
    que.push_back(v);
    second[v] = v;
    par[v] = s;
  }

  for (int i = 1; i < (int)que.size(); i++) {
    for (int v: G[que[i]]) {
      if (v == s) continue;
      if (second[v]) {
        if (second[v] == second[que[i]]) {
          continue;
        }
        cout << "Possible\n";
        vector<int> path1 = {v, que[i]};
        vector<int> path2 = {v, par[v]};
        while (path1.back() != s) path1.push_back(par[path1.back()]);
        while (path2.back() != s) path2.push_back(par[path2.back()]);
        reverse(path1.begin(), path1.end());
        reverse(path2.begin(), path2.end());
        for (vector<int> path: {path1, path2}) {
          cout << path.size() << '\n';
          for (int u: path) {
            cout << u << " ";
          }
          cout << '\n';
        }
        return 0;
      }
      second[v] = second[que[i]];
      par[v] = que[i];
      que.push_back(v);
    }
  }
  cout << "Impossible\n";

  /*
  for (int j = 0; j < K; j++) {
    par[s][j] = s;
  }

  function<bool(int, int)> is_ancestor = [&] (int u, int v) {
    
    return 0;
  };

  for (int i = 0; i < (int)que.size(); i++) {
    for (int v: G[que[i]]) {
      if (par[v][0]) {
        cout << v << " " << que[i] << " " << par[v][0] << endl;
      }

      else {
        que.push_back(v);
        par[v][0] = que[i];
        dist[v] = dist[que[i]]+1;
        for (int j = 1; j < K; j++) {
          par[v][j] = par[par[v][j-1]][j-1];
        }
      }
    }
  }
  */
}