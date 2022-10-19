#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

int read() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  return a + b + c + d;
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int s = read();
  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    int x = read();
    if (x > s)
      ++ans;
  }

  cout << ans + 1 << "\n";

}