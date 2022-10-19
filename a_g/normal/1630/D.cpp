#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int g = 0;
    for (int i = 0; i < m; i++) {
      int b;
      cin >> b;
      g = __gcd(g, b);
    }
    vector<int> flips(g);
    vector<int> mins(g, 1e9);
    vector<long long> sums(g);
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) flips[i%g]++;
      sums[i%g] += abs(a[i]);
      mins[i%g] = min(mins[i%g], abs(a[i]));
    }
    long long ans = -1e18;
    for (int z = 0; z < 2; z++) {
      long long m = 0;
      for (int i = 0; i < g; i++) {
        m += sums[i] - ((flips[i]&1)^z ? 2*mins[i] : 0);
      }
      ans = max(ans, m);
    }
    cout << ans << '\n';
  }
}