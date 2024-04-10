#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  string s(n, '0');
  int cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] > cur) {
      if (cur < q) {
        ++cur;
        s[i] = '1';
      }
    } else {
      s[i] = '1';
    }
  }

  cout << s << "\n";
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