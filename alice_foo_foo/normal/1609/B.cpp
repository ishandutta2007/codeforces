#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;

char c[maxN];
int n, q, ans;

bool check(int pos) {
  if (pos <= 0 || pos + 2 > n) return 0;
  return c[pos] == 'a' && c[pos + 1] == 'b' && c[pos + 2] == 'c';
}

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", c + 1);
  for (int i = 1; i <= n - 2; i++) ans += check(i);
  for (int i = 1; i <= q; i++) {
    int pos;
    scanf("%d", &pos);
    char foo = getchar();
    while (foo < 'a' || foo > 'c') foo = getchar();
    ans -= check(pos - 2); ans -= check(pos - 1); ans -= check(pos);
    c[pos] = foo;
    ans += check(pos - 2); ans += check(pos - 1); ans += check(pos);
    printf("%d\n", ans);
  }
  return 0;
}