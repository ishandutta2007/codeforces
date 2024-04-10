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
  int m;
  cin >> n;
  m = n;
  map<int, int> cnt;
  while (n--) {
    int t;
    cin >> t;
    while (t--) {
      int x;
      cin >> x;
      cnt[x]++;
    }
  }

  for (auto e : cnt)
    if (e.second == m)
      cout << e.first << " ";

  cout << "\n";
}