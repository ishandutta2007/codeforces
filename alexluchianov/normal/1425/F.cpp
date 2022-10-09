#include <bits/stdc++.h>

using namespace std;

int a[1005];
int sp[1005];

int ask(int l, int r) {
  printf("? %d %d\n", l, r);
  fflush(stdout);
  scanf("%d", &l);
  return l;
}

int main() {
  int n;
  scanf("%d", &n);
  int x = ask(2, 3);
  int y = ask(1, 3);
  a[1] = y - x;
  sp[1] = a[1];
  for (int i = 2; i <= n; ++i) {
    int t;
    if (i == 3)
      t = y;
    else
      t = ask(1, i);
    sp[i] = t;
    a[i] = sp[i] - sp[i - 1];
  }

  printf("! ");
  for (int i = 1; i <= n; ++i)
    printf("%d ", a[i]);
  fflush(stdout);


  return 0;
}