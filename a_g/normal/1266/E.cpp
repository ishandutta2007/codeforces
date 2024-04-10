#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N], b[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  long long z = accumulate(a+1, a+n+1, 0LL);
  int ex = 0;

  map<pair<int, int>, int> bonuses;
  int q;
  cin >> q;
  while (q--) {
    int s, t, u;
    cin >> s >> t >> u;
    int k = bonuses[{s, t}];

    if (k) {
      z -= max(a[k], b[k]);
      b[k]--;
      ex--;
      z += max(a[k], b[k]);
    }

    z -= max(a[u], b[u]);
    bonuses[{s, t}] = u;
    b[u]++;
    ex++;
    z += max(a[u], b[u]);

    cout << z-ex << '\n';
  }
}