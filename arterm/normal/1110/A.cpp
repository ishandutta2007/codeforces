#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int b, k;
  cin >> b >> k;
  int cur = 1;
  int ans = 0;
  vector<int> a(k);

  for (int i = 0; i < k; ++i) {
    cin >> a[k - 1 - i];
  }

  for (int i = 0; i < k; ++i) {
    ans = (ans + a[i] * cur) % 2;
    cur = (cur * b) % 2;
  }

  cout << (ans == 0 ? "even" : "odd") << "\n";

}