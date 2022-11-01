#include <bits/stdc++.h> 

using namespace std;

typedef pair <int, int> pii;

#define x first
#define y second

const int INF = 100 * 1000 * 1000;

char cmd[6];
int n, m, c, d, at[4], sz[4];
vector <pii> v[4];
int tr[300010];

bool cmp (pii a, pii b) {
  return a.y == b.y ? a.x < b.x : a.y > b.y;
}

bool pmc (pii a, pii b) {
  return a.x == b.x ? a.y > b.y : a.x < b.x;
}

void upd (int p, int v) {
  for (tr[p += m] = v; p > 1; p >>= 1) {
    tr[p >> 1] = max(tr[p], tr[p ^ 1]);
  }
}

int qur (int l, int r) {
  int ret = -1111;
  for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret = max(ret, tr[l++]);
    if (r & 1) ret = max(ret, tr[--r]);
  }
  return ret;
}

int solve (vector <pii> &z, int cost) {
  m = z.size();
  sort(z.begin(), z.end(), pmc);
  vector <int> yy;
  for (int i = 0; i < m; ++i) {
    yy.push_back(z[i].x);
  }
  for (int i = 0; i < m; ++i) {
    tr[m + i] = z[i].y;
  }
  for (int i = m - 1; i; --i) {
    tr[i] = max(tr[i << 1], tr[i << 1 | 1]);
  }
  int ret = 0;
  for (int i = 0; i < m; ++i) {
    int cur = z[i].y, prc = z[i].x;
    int rem = cost - prc;
    // cout << rem << " ";
    if (rem <= 0) continue;
    int pos = upper_bound(yy.begin(), yy.end(), rem) - yy.begin();
    pos = min(pos, m);
    // cout << pos << endl;
    upd(i, -INF);
    int val = qur(0, pos);
    // cout << val << endl;
    upd(i, cur);
    if (val > 0) ret = max(ret, cur + val);
  }
  return ret;
}

int main (int argc, char const *argv[]) {
  scanf("%d %d %d", &n, &c, &d);
  for (int i = 1; i <= n; ++i) {
    int b, p;
    scanf("%d %d %s", &b, &p, cmd);
    if (cmd[0] == 'C') {
      v[0].push_back({p, b});
    } else {
      v[1].push_back({p, b});
    }
  }
  sort(v[0].begin(), v[0].end(), cmp);
  sort(v[1].begin(), v[1].end(), cmp);
  sz[0] = v[0].size(), sz[1] = v[1].size();
  int tot = 0;
  // differents
  at[0] = at[1] = 0;
  while (at[0] < sz[0] and v[0][at[0]].x > c) {
    ++at[0];
  }
  while (at[1] < sz[1] and v[1][at[1]].x > d) {
    ++at[1];
  }
  if (at[0] < sz[0] and at[1] < sz[1]) {
    tot = max(tot, v[0][at[0]].y + v[1][at[1]].y);
  }
  if (sz[0] > 1) tot = max(tot, solve(v[0], c));
  if (sz[1] > 1) tot = max(tot, solve(v[1], d));
  cout << tot << endl;
  return 0;
}