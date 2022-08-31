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
  vector <int> x(n), y(n), z(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  auto f = [&] (int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]) + abs(z[i] - z[j]);
  };
  vector <pair <int, int> > e;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      e.push_back({i, j});
    }
  }
  sort(e.begin(), e.end(), [&] (pair <int, int> a, pair <int, int> b) {
    return f(a.first, a.second) < f(b.first, b.second);
  });
  vector <bool> u(n);
  for (auto c : e) {
    if (!u[c.first] && !u[c.second]) {
      cout << c.first + 1 << ' ' << c.second + 1 << '\n';
      u[c.first] = u[c.second] = true;
    }
  }
}