#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 100100;

int a[M];

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int mn = *min_element(a, a + n);
  int mx = *max_element(a, a + n);

  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (a[i] != mn && a[i] != mx)
      ++ans;

  cout << ans << endl;

}