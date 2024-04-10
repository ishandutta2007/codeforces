#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char s[N];
bitset <N> bad;
int pf[N], sf[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    pf[i] = pf[i - 1] + (s[i] == '(');
  }
  for (int i = n; i >= 1; --i) {
    sf[i] = sf[i + 1] + (s[i] == ')');
  }
  int last = 0;
  for (int i = 1; i <= n; ++i) {
    if (pf[i] <= sf[i + 1]) {
      last = i;
    }
  }
  int rem = pf[last];
  for (int i = 1; i <= n and rem > 0; ++i) {
    if (s[i] == '(') {
      bad[i] = 1;
      --rem;
    }
  }
  rem = sf[last + 1];
  for (int i = n; i >= 1 and rem > 0; --i) {
    if (s[i] == ')') {
      bad[i] = 1;
      --rem;
    }
  }
  if (bad.count() == 0) {
    cout << "0\n";
  } else {
    cout << "1\n" << bad.count() << '\n';
    for (int i = 1; i <= n; ++i) if (bad[i]) printf("%d ", i); 
    puts("");
  }
  // for (int i = 1; i <= n; ++i) {
  //   if (!bad[i]) putchar(s[i]);
  // }
  // puts("");
  return 0;
}