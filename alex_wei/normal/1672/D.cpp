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
int n, a[N], b[N], cnt[N];
void solve(int T) {
  cin >> n, b[n + 1] = 0;
  for(int i = 1; i <= n; i++) cnt[i] = 0;
  for(int i = 1; i <= n; i++) a[i] = read();
  for(int i = 1; i <= n; i++) b[i] = read();
  int pt = 1;
  for(int i = 1; i <= n; i++) {
    while(b[i] != a[pt] && pt <= n) cnt[a[pt++]]++;
    if(pt > n) return puts("NO"), void();
    if(cnt[a[pt]]) cnt[a[pt]]--;
    else pt++;
  }
  puts("YES");
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) solve(T);
  return 0;
}