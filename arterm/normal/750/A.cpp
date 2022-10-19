#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n, k;

  cin >> n >> k;

  int t = 240 - k;

  t /= 5;

  int i = 0;
  while (i < n && t >= i + 1) {
    ++i;
    t -= i;
  }

  cout << i << endl;
}