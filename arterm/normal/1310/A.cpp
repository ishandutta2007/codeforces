#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;

ll a[M], t[M];
pair<ll, ll> b[M];

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    b[i] = make_pair(a[i], t[i]);
  }

  sort(b, b + n);

  ll sum = 0;
  ll ans = 0;
  multiset<int> rem;
  ll cur = 0;
  int i = 0;
  while (i < n || !rem.empty()) {
    if (rem.empty()) {
      cur = b[i].first;
    }

    while (i < n && cur == b[i].first) {
      rem.insert(-b[i].second);
      sum += b[i].second;
      ++i;
    }

    if (!rem.empty()) {
      ll mn = -*rem.begin();
      rem.erase(rem.begin());
      sum -= mn;
      ans += sum;
      ++cur;
    }
  }

  cout << ans << "\n";
}