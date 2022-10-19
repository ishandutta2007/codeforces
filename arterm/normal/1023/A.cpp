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

  int n, m;
  string s, t;

  cin >> n >> m;
  cin >> s >> t;

  if (find(all(s), '*') == s.end()) {
    cout << (s == t ? "YES" : "NO") << "\n";
    return 0;
  }

  int x = find(all(s), '*') - s.begin();

  if (m < n - 1) {
    cout << "NO\n";
    return 0;
  }

  bool ans = (s.substr(0, x) == t.substr(0, x)) &&
    (s.substr(x + 1, n - x - 1) == t.substr(m - (n - x - 1), n - x - 1));
  if (ans)
    cout << "YES\n";
  else
    cout << "NO\n";

}