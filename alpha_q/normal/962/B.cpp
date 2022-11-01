#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

char s[N];
int n, a, b;

int main() {
  cin >> n >> a >> b;
  scanf("%s", s + 1);
  int ans = a + b;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '*') continue;
    int j = i, len = 0;
    while (j <= n and s[j] == '.') ++j, ++len;
    if (a > b) swap(a, b); 
    int one = len >> 1, two = len - one;
    if (a >= one) {
      a -= one;
      if (b >= two) b -= two; else b = 0;
    } else {
      a = 0;
      if (b >= two) b -= two; else b = 0;
    }
    i = j;
  }
  ans -= (a + b);
  cout << ans << '\n';
  return 0;
}