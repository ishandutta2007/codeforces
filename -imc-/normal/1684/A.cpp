#include <bits/stdc++.h>

using namespace std;

using li = long long;

#define all(v) (v).begin(), (v).end()

void solve(bool read) {
  int x;
  cin >> x;

  vector<int> d;
  while (x) {
    d.push_back(x % 10);
    x /= 10;
  }
  reverse(all(d));

  if (d.size() >= 3) {
    cout << *min_element(all(d)) << "\n";
  } else {
    cout << d[1] << "\n";
  }

  // at least 3: min ok
  // 2:
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //while (true) solve(false);

  return 0;
}