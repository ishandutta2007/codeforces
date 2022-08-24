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
  int n;
  cin >> n;
  vector <int> a(n);
  vector <pair <int, int> > b;
  vector <int> l(n), r(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    l[i] = a[i] / 2;
    r[i] = a[i] / 2;
    if (a[i] % 2) {
      if (a[i] < 0) r[i]--;
      else r[i]++;
    }
    sum += l[i];
  }
  for (int i = 0; i < n; i++) {
    if (sum == 0) {
      cout << l[i] << '\n';
    } else {
      sum += r[i] - l[i];
      cout << r[i] << '\n';
    }
  }
}