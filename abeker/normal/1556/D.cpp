#include <bits/stdc++.h>
using namespace std;

int input() {
  int x;
  scanf("%d", &x);
  return x;
}

int ask_or(int x, int y) {
  printf("or %d %d\n", x, y);
  fflush(stdout);
  return input();
}

int ask_and(int x, int y) {
  printf("and %d %d\n", x, y);
  fflush(stdout);
  return input();
}

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  vector <int> a(N + 1);
  int lb = 0, ub = (1 << 30) - 1;
  for (int i = 2; i <= N; i++) {
    int large = ask_or(1, i);
    int small = ask_and(1, i);
    a[i] = large ^ small;
    lb |= small;
    ub &= large;
  }
  int other = ask_or(2, 3);
  for (int i = 0; i < 30; i++) {
    int small = lb >> i & 1;
    int large = ub >> i & 1;
    if (small != large)
      a[1] |= !(other >> i & 1) << i;
    else
      a[1] |= small << i;
  }
  for (int i = 2; i <= N; i++)
    a[i] ^= a[1];
  sort(a.begin() + 1, a.end());
  printf("finish %d\n", a[K]);
  fflush(stdout);
  return 0;
}