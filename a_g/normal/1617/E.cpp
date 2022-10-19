#include <bits/stdc++.h>
using namespace std;

int parent(int k) {
  if (k <= 1) return 0;
  return (1<<(32-__builtin_clz(k-1)))-k;
}

int dist(int x, int y) {
  int ans = 0;
  while (x != y) {
    ans++;
    if (x > y) x = parent(x);
    else y = parent(y);
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x = 0;
  for (int i = 1; i < n; i++) {
    if (dist(a[i], a[0]) > dist(a[x], a[0])) x = i;
  }
  int y = 0;
  for (int i = 1; i < n; i++) {
    if (dist(a[i], a[x]) > dist(a[y], a[x])) y = i;
  }
  cout << x+1 << ' ' << y+1 << ' ' << dist(a[x], a[y]) << '\n';
}