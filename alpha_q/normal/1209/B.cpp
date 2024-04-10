#include <bits/stdc++.h>

using namespace std;

const int N = 105;

string s;
int n, a[N], b[N];

int main() {
  clock_t st = clock();
  cin >> n >> s;
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  int it, ans = 0;
  for (it = 0; clock() < st + 0.9 * CLOCKS_PER_SEC; ++it) {
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (it < b[i]) cur += s[i] - '0';
      else {
        int add = (it - b[i]) / a[i];
        add &= 1; if (s[i] == '0') add ^= 1;
        cur += add; 
      }
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}