#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& a) {
  for (int x: a) {
    cout << x << ' ';
  }
  cout << endl;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<bool> f(n);
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if ((x <= n)==(y <= n)) {
      cout << "-1\n";
      return 0;
    }
    if (x > y) {
      swap(x, y);
      f[x-1] = 1;
    }
    p[y-n-1] = x;
  }
  vector<int> suffmax = p, prefmin = p;
  for (int i = 1; i < n; i++) {
    prefmin[i] = min(prefmin[i-1], prefmin[i]);
  }
  for (int i = n-2; i >= 0; i--) {
    suffmax[i] = max(suffmax[i+1], suffmax[i]);
  }
  for (int i = 1; i < n-1; i++) {
    if (p[i] > prefmin[i-1] && p[i] < suffmax[i+1]) {
      cout << "-1\n";
      return 0;
    }
  }

  int ans = 0;
  int l = 0;
  auto solve = [&] (int l, int r) {
    int z[2] = {0, 0};
    for (int i = l; i <= r; i++) {
      if (i > 0 && p[i] > prefmin[i-1]) {
        z[f[p[i]-1]]++;
      }
      else if (i < n-1 && p[i] < suffmax[i+1]) {
        z[f[p[i]-1]^1]++;
      }
    }
    ans += min(z[0], z[1]);
  };
  for (int i = 0; i < n; i++) {
    if (prefmin[i] == n-i) {
      solve(l, i);
      l = i+1;
    }
  }

  cout << ans << '\n';
}