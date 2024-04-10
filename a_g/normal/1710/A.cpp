#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int& x: a) cin >> x;
    long long tot = 0;
    bool f = 0;
    for (int x: a) {
      int z = x/n;
      if (z >= 3) f = 1;
      tot += (z >= 2 ? z : 0);
    }
    if ((tot >= m) && ((tot-m)%2 == 0 || f)) {
      cout << "Yes\n";
      continue;
    }

    tot = 0;
    f = 0;
    for (int x: a) {
      int z = x/m;
      if (z >= 3) f = 1;
      tot += (z >= 2 ? z : 0);
    }
    if ((tot >= n) && ((tot-n)%2 == 0 || f)) {
      cout << "Yes\n";
      continue;
    }
    cout << "No\n";
  }
}