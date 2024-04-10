#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int n, k; char s[N];

int main() {
  scanf("%d %d %s", &n, &k, s + 1); 
  for (int i = 1; i <= n; ++i) s[n + i] = s[i];
  int at = -1;
  for (int i = 1; i <= n; ++i) if (s[i] == s[i + 1]) {
    at = i; break;
  }
  if (at == -1) {
    if (k & 1) for (int i = 1; i <= n; ++i) s[i] = s[i] == 'W' ? 'B' : 'W';
    s[n + 1] = 0; puts(s + 1);
    return 0;
  }
  for (int i = 1, j = at + 1; i <= n; ++i, ++j) s[i] = s[j];
  for (int i = 1; i <= n; ++i) s[n + i] = s[i];
  for (int i = 2; i < n; ++i) {
    if (s[i] == s[i - 1] or s[i] == s[i + 1]) continue;
    int j = i;
    while (j < n and s[j] != s[j + 1]) ++j;
    int len = j - i;
    if (s[i] != s[j]) {
      char a = s[i], b = s[j];
      int moves = 1 + len >> 1;
      if (k >= moves) {
        for (int p = i; p < j; ++p) s[p] = b;
      } else {
        int p, q, rem;
        for (p = i, q = j - 1, rem = k; rem > 0; --rem, ++p, --q) {
          s[p] = s[q] = b;
        }
        for (int r = p, pr = 0; r <= q; ++r, pr ^= 1) s[r] = pr ? b : a; 
      }
    } else {
      char a = s[i], b = s[j - 1];
      int moves = len >> 1;
      if (k >= moves) {
        for (int p = i, it = 0; p < j; ++p, ++it) s[p] = it < moves ? b : a;
      } else {
        int p, q, rem;
        for (p = i, q = j - 1, rem = k; rem > 0; --rem, ++p, --q) {
          s[p] = b, s[q] = a;
        }
        for (int r = p, pr = 0; r <= q; ++r, pr ^= 1) s[r] = pr ? b : a;  
      }
    }
    i = j;
  }
  for (int i = 1; i <= n; ++i) s[n + i] = s[i];
  for (int i = n + n; i >= n + 1; --i) s[i] = s[i - at];
  for (int i = 1; i <= n; ++i) s[i] = s[n + i];
  s[n + 1] = 0; puts(s + 1);
  return 0;
}