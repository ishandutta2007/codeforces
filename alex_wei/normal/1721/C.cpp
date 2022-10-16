#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 5;
int n, a[N], b[N], lst[N];
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];
  lst[n + 1] = n + 1;
  for(int i = n; i > 1; i--) {
    if(a[i] <= b[i - 1]) lst[i] = lst[i + 1];
    else lst[i] = i;
  }
  for(int i = 1; i <= n; i++) cout << b[lower_bound(b + 1, b + n + 1, a[i]) - b] - a[i] << " ";
  cout << "\n";
  for(int i = 1; i <= n; i++) cout << b[lst[i + 1] - 1] - a[i] << " ";
  cout << "\n";
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}