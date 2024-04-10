#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#define maxn 300005

using namespace std;
typedef long long ll;
int t, n, a[maxn];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  puts(a[1] > a[n] ? "NO" : "YES");
}
int main() {
  cin >> t;
  while (t--) solve();
  return 0;
}