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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    
    bool ok = false;
    for (int i = 0; i + 1 < n; ++i)
      if (abs(a[i + 1] - a[i]) >= 2) {
        ok = true;
        cout << "YES\n";
        cout << i + 1 << " " << i + 2 << "\n";
        break;
      }
    if (!ok) {
      cout << "NO\n";
    }
  }

}