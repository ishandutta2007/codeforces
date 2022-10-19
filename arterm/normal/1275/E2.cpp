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

  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x), b(y);
    for (int i = 0; i < x; ++i)
      cin >> a[i];
    for (int i = 0; i < y; ++i)
      cin >> b[i];

    if (*max_element(all(a)) > *max_element(all(b)))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

}