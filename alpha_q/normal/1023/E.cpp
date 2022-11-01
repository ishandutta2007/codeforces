#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int n, x, y, ptr;
char cmd[7], ans[N];

bool ask (int r_1, int c_1, int r_2, int c_2) {
  assert(r_1 <= r_2 and c_1 <= c_2 and r_2 + c_2 - r_1 - c_1 >= n - 1);
  printf("? %d %d %d %d\n", r_1, c_1, r_2, c_2);
  fflush(stdout);
  scanf("%s", cmd);
  assert(cmd[0] != 'B');
  return (cmd[0] == 'Y');
}

// ******
// ******
// ******
// **_***
// ******
// ******

bool valid (int x, int y) {
  return ((x > 0) and (y > 0) and (x <= n) and (y <= n));
}

int main() {
  scanf("%d", &n);
  
  x = y = 1, ptr = 0;
  
  for (int i = 1; i < n; ++i) {
    if (valid(x, y + 1) and ask(x, y + 1, n, n)) {
      ++y, ans[++ptr] = 'R';
    } else {
      ++x, ans[++ptr] = 'D';
    }
  }

  int pre_x = x, pre_y = y;
  
  x = y = n, ptr = n + n - 1;
  
  for (int i = 1; i < n; ++i) {
    if (valid(x - 1, y) and ask(1, 1, x - 1, y)) {
      --x, ans[--ptr] = 'D';
    } else {
      --y, ans[--ptr] = 'R';
    }
  }

  assert(pre_x == x and pre_y == y);
  
  printf("! ");
  for (int i = 1; i <= n + n - 2; ++i) {
    putchar(ans[i]);
  }
  puts("");
  fflush(stdout);
  return 0;
}