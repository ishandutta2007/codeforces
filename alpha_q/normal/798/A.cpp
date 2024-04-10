#include <bits/stdc++.h> 

using namespace std;

char s[100];
int n;

int main (int argc, char const *argv[]) {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int dif = 0;
  for (int i = 1; i + i <= n; ++i) {
    if (s[i] != s[n + 1 - i]) {
      ++dif;
    }
  }
  if (dif > 1) puts("NO");
  else if (dif == 0) {
    if (n & 1) puts("YES");
    else puts("NO");
  } else {
    puts("YES");
  }
  return 0;
}