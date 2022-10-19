#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=2e5;

int vals[maxn];
int targets[maxn];
ll valparts[2];
ll targetparts[2];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nbrs(n);
    ll totalval = 0;
    ll totaltarget = 0;
    for (int i = 0; i < n; i++) {
      cin >> vals[i];
      totalval += vals[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> targets[i];
      totaltarget += targets[i];
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
    }

    bool bipartite = 1;
    for (int i = 0; i < 2; i++) {
      valparts[i] = 0;
      targetparts[i] = 0;
    }
    queue<int> q;
    q.push(0);
    vector<int> partsmap(n, -1);
    partsmap[0] = 0;
    while (!q.empty() && bipartite) {
      int v = q.front();
      int part = partsmap[v];
      valparts[part] += vals[v];
      targetparts[part] += targets[v];
      q.pop();
      for (int u: nbrs[v]) {
        if (partsmap[u] == -1) {
          partsmap[u] = (part + 1) % 2;
          q.push(u);
        }
        else if (partsmap[u] == part) {
          bipartite = 0;
          break;
        }
      }
    }
    if (!bipartite) {
      cout << ((totalval & 1)^(totaltarget & 1) ? "NO\n" : "YES\n");
    }
    else {
      bool good = (valparts[0] + targetparts[1]) == (valparts[1] + targetparts[0]);
      cout << (good ? "YES\n" : "NO\n");
    }
  }

}