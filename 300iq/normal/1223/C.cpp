#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i] /= 100;
    }
    int x, a;
    cin >> x >> a;
    int y, b;
    cin >> y >> b;
    ll k;
    cin >> k;
    vector <ll> f(n);
    for (int i = a - 1; i < n; i += a) {
      f[i] += x;
    }
    for (int i = b - 1; i < n; i += b) {
      f[i] += y;
    }
    sort(p.rbegin(), p.rend());
    auto check = [&] (int x) {
      vector <int> orz;
      for (int i = 0; i < x; i++) {
        orz.push_back(f[i]);
      }
      sort(orz.rbegin(), orz.rend());
      ll sum = 0;
      for (int i = 0; i < x; i++) {
        sum += p[i] * orz[i];
      }
      return sum >= k;
    };
    if (!check(n)) {
      cout << -1 << '\n';
    } else {
      int l = 0, r = n;
      while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m)) {
          r = m;
        } else {
          l = m;
        }
      }
      cout << r << '\n';
    }
  }
}