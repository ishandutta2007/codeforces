#include <cstdio>

char s[5005], t[5005];

int a[5005][5005], i, j, ans;

#define mod 1000000007

int main(void) {
  gets(s);
  gets(t);

  for (i = 0; s[i]; i++)
    for (j = 0; t[j]; j++)
      a[i + 1][j + 1] = (a[i + 1][j] + (t[j] == s[i]) * (a[i][j] + 1)) % mod;

  for (i = 0; s[i]; i++)
    ans = (ans + a[i + 1][j]) % mod;
  
  printf("%d\n", ans);
}