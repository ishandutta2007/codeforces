#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n*n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        edges[x-1] = make_pair(i, j);
      }
    }
    cout << "B" << endl;
    bool transpose;
    int k;
    {
      char c;
      cin >> c >> k;
      if (c == 'I') {
        reverse(edges.begin(), edges.end());
      }
      transpose = (k <= n);
      if (transpose) {
        for (auto& [u, v]: edges) {
          swap(u, v);
        }
      }
    }

    vector<vector<int>> pref_list(n);
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n*n; i++) {
      int u = edges[i].first;
      int v = edges[i].second;
      pref_list[u].push_back(v);
      a[u][v] = i;
    }

    vector<int> propose_to(n);
    vector<bool> free_r(n, 1);
    vector<int> match(n, -1);
    while (any_of(free_r.begin(), free_r.end(), [&] (bool b) {return b;})) {
      for (int i = 0; i < n; i++) {
        if (free_r[i]) {
          assert(propose_to[i] < n);
          int v = pref_list[i][propose_to[i]];
          propose_to[i]++;
          if (match[v] == -1) {
            free_r[i] = 0;
            match[v] = i;
          }
          else if (a[i][v] > a[match[v]][v]) {
            free_r[match[v]] = 1;
            free_r[i] = 0;
            match[v] = i;
          }
          break;
        }
      }
    }

    while (k > 0) {
      if (!transpose) k -= n;
      k--;
      cout << match[k]+1+transpose*n << endl;
      cin >> k;
    }
  }
}