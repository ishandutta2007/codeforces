#include <bits/stdc++.h>

using namespace std;

int n, q, x, y;
map<int, pair<char, int>> m;

int query() {
  char c;
  scanf("%d%d%c%c", &x, &y, &c, &c);
  auto b = m.lower_bound(x);
  if (b->first == x) return 0;
  if (c == 'L') --b;
  int ans = abs(b->first - x);
  if (b->second.first == c) ans += b->second.second;
  m[x] = {c, ans};
  return ans;
}

int main() {
  scanf("%d%d", &n, &q);
  m[0] = {'U', 0};
  m[n+1] = {'L', 0};
  for (; q; --q) printf("%d\n", query());
  return 0;
}