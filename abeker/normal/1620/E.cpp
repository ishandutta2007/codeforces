#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e5 + 5;

int Q;
int which[MAX];
stack <int> ans;

void solve(int q) {
  if (!q)
    return;
  int t, x, y;
  scanf("%d%d", &t, &x);
  if (t == 2)
    scanf("%d", &y);
  solve(q - 1);
  if (t == 1)
    ans.push(which[x]);
  else
    which[x] = which[y];
}

int main() {
  scanf("%d", &Q);
  iota(which, which + MAX, 0);
  solve(Q);
  for (; !ans.empty(); ans.pop())
    printf("%d ", ans.top());
  puts("");
  return 0;
}