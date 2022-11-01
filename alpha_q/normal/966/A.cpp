#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 5;

int n, m, cl, ce, v, q;
vector <int> st, el;

int solve (int a, int b, int c, int d) {
  if (a == c) return abs(b - d);
  int p, res = INF;
  p = lower_bound(st.begin(), st.end(), b) - st.begin();
  // cout << p << endl;
  if (p < cl) res = min(res, abs(st[p] - b) + abs(a - c) + abs(st[p] - d));
  --p;
  if (p >= 0) res = min(res, abs(st[p] - b) + abs(a - c) + abs(st[p] - d));
  p = lower_bound(el.begin(), el.end(), b) - el.begin();
  // cout << p << endl;
  if (p < ce) res = min(res, abs(el[p] - b) + (abs(a - c) + v - 1) / v + abs(el[p] - d));
  --p;
  if (p >= 0) res = min(res, abs(el[p] - b) + (abs(a - c) + v - 1) / v + abs(el[p] - d));
  return res;
}

int main() {
  cin >> n >> m >> cl >> ce >> v;
  st.resize(cl), el.resize(ce);
  for (int i = 0; i < cl; ++i) scanf("%d", &st[i]);
  for (int i = 0; i < ce; ++i) scanf("%d", &el[i]);
  cin >> q;
  while (q--) {
    int x_1, y_1, x_2, y_2, p;
    scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
    // cout << x_1 << " " << x_2 << " " << y_1 << " " << y_2 << endl;
    int ans = min(solve(x_1, y_1, x_2, y_2), solve(x_2, y_2, x_1, y_1));
    printf("%d\n", ans);
  }
  return 0;
}