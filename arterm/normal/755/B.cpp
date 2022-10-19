#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n, m;

  cin >> n >> m;

  set<string> s;

  for (int i = 0; i < n; ++i) {
    string t;
    cin >> t;
    s.insert(t);
  }

  int a = 0, b = 0, c = 0;

  for (int i = 0; i < m; ++i) {
    string t;
    cin >> t;
    if (s.find(t) != s.end()) {
      ++b;
    }
  }

  a = n - b;
  c = m - b;

  int A = a + (b + 1) / 2;
  int B = c + (b / 2);
  if (A > B)
    cout << "YES\n";
  else
    cout << "NO\n";
}