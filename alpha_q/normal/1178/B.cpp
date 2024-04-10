#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

char s[N];
long long pf[N], sf[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    pf[i] = pf[i - 1];
    if (i > 1 and s[i] == s[i - 1] and s[i] == 'v') ++pf[i];
  }
  for (int i = n; i >= 1; --i) {
    sf[i] = sf[i + 1];
    if (i < n and s[i] == s[i + 1] and s[i] == 'v') ++sf[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'o') ans += pf[i] * sf[i];
  }
  cout << ans << endl;
  return 0;
}