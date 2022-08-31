#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <bool> used(3 * n);
    vector <int> ans;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      if (!used[a] && !used[b]) {
          ans.push_back(i + 1);
          used[a] = true, used[b] = true;
      }
    }
    if (ans.size() >= n) {
      cout << "Matching\n";
      ans.resize(n);
      for (int i : ans) {
        cout << i << ' ';
      }
      cout << '\n';
    } else {
      ans.clear();
      for (int i = 0; i < 3 * n; i++) if (!used[i]) ans.push_back(i + 1);
      ans.resize(n);
      cout << "IndSet\n";
      for (int i : ans) {
        cout << i << ' ';
      }
      cout << '\n';
    }
  }
}