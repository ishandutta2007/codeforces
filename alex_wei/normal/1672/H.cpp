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
int n, q, a[N], b[N];
char s[N];
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> q >> s + 1;
  for(int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + (s[i] == '0' && s[i - 1] == '0');
    b[i] = b[i - 1] + (s[i] == '1' && s[i - 1] == '1');
  }
  for(int i = 1; i <= q; i++) {
    int l = read(), r = read();
    int cnt0 = a[r] - a[l], cnt1 = b[r] - b[l];
    cout << max(cnt0, cnt1) + 1 << "\n";
  }
  return 0;
}