#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  reverse(all(a));

  while (true) {
    if (a.size() == 1) { break; }

    int until = a.size() - 1;
    for (int i = 0; i + 1 < a.size(); ++i) {
      if (!a[i]) {
        until = i;
        break;
      }

      a[i] -= a[i + 1];
    }
    a.pop_back();

    until = min<int>(until, a.size());
    sort(a.begin(), a.begin() + until, std::greater<int>());
  }
  assert(a.size() == 1);

  cout << a[0] << "\n";
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