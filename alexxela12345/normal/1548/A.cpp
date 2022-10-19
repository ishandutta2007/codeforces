#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> cnt(n);
  int m;
  cin >> m;

  int ans = n;
  auto addEdge = [&](int a, int b) {
    if (b < a)
      swap(a, b);
    cnt[a]++;
    if (cnt[a] == 1) {
      ans--;
    }
  };

  auto remEdge = [&](int a, int b) {
    if (b < a)
      swap(a, b);
    cnt[a]--;
    if (cnt[a] == 0)
      ans++;
  };
  
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    addEdge(a, b);
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 3) {
      cout << ans << '\n';
    } else if (t == 1) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      addEdge(a, b);
    } else {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      remEdge(a, b);
    }
  }
}