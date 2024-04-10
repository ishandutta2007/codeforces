#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<ll> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  string ans[] = {"sjfnb", "cslnb"};

  bool bad = false;

  sort(all(a));
  for (int i = 0; i + 1 < n; ++i)
    if (a[i] == a[i + 1]) {
      if (a[i] == 0) {
        cout << ans[1] << "\n";
        return 0;
      }

      bad = true;
      --a[i];
      break;
    }

  if (bad) {
    for (int i = 0; i + 1 < n; ++i)
      if (a[i] == a[i + 1]) {
        cout << ans[1] << "\n";
        return 0;
      }
  }

  ll rem = 0;
  for (int i = 0; i < n; ++i) {
    assert(i <= a[i]);
    rem += a[i] - i;
  }

  if (bad)
    rem++;

  cout << ans[(rem + 1) % 2] << "\n";
}