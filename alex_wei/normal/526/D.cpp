#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
bool Mbe;
constexpr int N = 1e6 + 5;
char s[N];
int n, k, nxt[N], z[N], ok[N];
bool Med;
int main() {
  fprintf(stderr, "%.4lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  cin >> n >> k >> s + 1;
  for(int i = 2, j = 0; i <= n; i++) {
    while(j && s[j + 1] != s[i]) j = nxt[j];
    nxt[i] = j += s[j + 1] == s[i];
  }
  for(int i = 2, l = 0, r = 0; i <= n; i++) {
    z[i] = i <= r ? min(r - i + 1, z[i - l + 1]) : 0;
    while(s[1 + z[i]] == s[i + z[i]]) z[i]++;
    if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  for(int i = k; i <= n; i += k) {
    if(i / k % (i - nxt[i])) continue;
    ok[i]++, ok[min(n, i + min(i / k, z[i + 1])) + 1]--;
  }
  for(int i = 1; i <= n; i++) cout << ((ok[i] += ok[i - 1]) > 0);
  cout << "\n";
  return cerr << 1e3 * clock() / CLOCKS_PER_SEC << " ms\n", 0;
}
/*
2022/7/25
start coding at 19:46
finish debugging at 19:54
*/