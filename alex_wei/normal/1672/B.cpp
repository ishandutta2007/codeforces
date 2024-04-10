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
char s[N];
void solve() {
  cin >> s + 1;
  int n = strlen(s + 1), A = 0;
  for(int i = 1; i <= n; i++) {
    if(s[i] == 'A') A++;
    else A--;
    if(A < 0) return puts("NO"), void();
  }
  if(s[n] == 'A') puts("NO");
  else puts("YES");
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