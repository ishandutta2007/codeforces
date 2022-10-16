#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
constexpr int N = 2e5 + 5;
int n, a[N];
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) a[i] = read();
  int fst = -1, lst = -1;
  for(int i = 1; i < n; i++) if(a[i] == a[i + 1]) lst = i;
  for(int i = n - 1; i; i--) if(a[i] == a[i + 1]) fst = i;
  if(fst < lst) cout << max(lst - fst - 1, 1) << "\n";
  else puts("0");
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}