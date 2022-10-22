#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  int na, nb;
  cin >> na >> nb;
  string a, b;
  cin >> a >> b;

  for (int i = 1; i < b.size(); ++i) {
    if (a[a.size() - b.size() + i] != b[i]) {
      cout << "NO\n";
      return;
    }
  }

  std::array<bool, 2> have{};
  for (int i = 0; i <= a.size() - b.size(); ++i) {
    have[a[i] - '0'] = true;
  }

  //cout << have[0] << " " << have[1] << "\n";

  cout << ((!have[b[0] - '0']) ? "NO" : "YES") << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#endif

  //solve(false);

  return 0;
}