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

  int n;
  int ans = 0;
  cin >> n;
  set<int> x;

  for (int i = 0; i < n; ++i) {
    int y;
    cin >> y;
    x.insert(y);
  }

  while (!x.empty()) {
    int t = *x.begin();
    for (int i = 1; i <= 100; ++i)
      x.erase(i * t);
    ++ans;
  }

  cout << ans << "\n";

}