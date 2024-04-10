#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pos(n);

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      --x;

      pos[x].push_back(i);
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    sort(p.begin(), p.end(), [&](int x, int y) -> bool {
      return pos[x].size() > pos[y].size();
    });

//    for (int i = 0; i < n; ++i)
//      cerr << pos[p[i]].size() << " ";
//    cerr << endl;

    vector<int> b(n);

    while (!pos[p[0]].empty()) {
      int i = 0;
      vector<int> cur;
      while (i < n && !pos[p[i]].empty()) {
        cur.push_back(pos[p[i]].back());
        pos[p[i]].pop_back();
        ++i;
      }

      for (int j = 0; j < i; ++j) {
        b[cur[(j + 1) % i]] = p[j];
      }
    }

    for (int x : b)
      cout << x + 1 << " ";
    cout << "\n";
  }

  return 0;
}