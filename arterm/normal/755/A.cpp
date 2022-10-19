#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
#ifdef LOCAL
  assert(freopen(".in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  if (n + 2 <= 1000) {
    cout << n + 2 << endl;
  } else {
    cout << n - 2 << endl;
  }
}