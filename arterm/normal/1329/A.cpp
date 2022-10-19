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
  cin >> n >> m;
  vector<int> l(m);
  ll sum = 0;
  for (int i = 0; i < m; ++i) {
    cin >> l[i];
    sum += l[i];
  }

  if (sum < n) {
    cout << "-1\n";
    return 0;
  }


  for (int i = 0; i < m; ++i)
    if (l[i] + i > n) {
      cout << "-1\n";
      return 0;
    }

  vector<int> ans(m);
  int last = 0;
  for (int i = m - 1; i >= 0; --i) {
    ans[i] = min(last, n - l[i] - i);
    last = max(last, ans[i] + l[i]);
  }

  for (int i = 0; i < m; ++i)
    cout << ans[i] + 1 << " ";
  cout << "\n";

}