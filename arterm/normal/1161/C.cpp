#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int mn = *min_element(all(a));
  int cnt = 0;
  for (int x : a)
    if (x == mn)
      ++cnt;

  if (cnt <= n / 2)
    cout << "Alice\n";
  else
    cout << "Bob\n";

}