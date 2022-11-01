#include <bits/stdc++.h>

using namespace std;

const int LG = 20;
const int N = 200010;

vector <int> lt, rt;
vector <int> vec[N];
vector <pair <int, int>> pr;
int n, m, q, sz, p[N], rev[N], a[N], last[N], spt[N][LG], t[N + N];

inline int nxt (int i) {
  return i == n ? 1 : i + 1;
}

int query (int l, int r) {
  int ret = 69 * N;
  for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret = min(ret, t[l++]);
    if (r & 1) ret = min(ret, t[--r]);
  }
  return ret;
}

int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", p + i);
    rev[p[i]] = i;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", a + i);
    a[i] = rev[a[i]];
  }
  for (int i = m; i >= 1; --i) {
    if (last[nxt(a[i])]) spt[i][0] = last[nxt(a[i])];
    last[a[i]] = i;
  }
  // for (int i = 1; i <= m; ++i) {
  //   cout << i << " --> " << spt[i][0] << endl;
  // }
  for (int j = 1; j < LG; ++j) {
    for (int i = 1; i <= m; ++i) {
      if (spt[i][j - 1]) spt[i][j] = spt[spt[i][j - 1]][j - 1];
    }
  }
  for (int i = 1; i <= m; ++i) {
    int l = i, r = i, rem = n - 1, good = 1;
    for (int j = LG - 1; j >= 0; --j) {
      if (rem >= (1 << j)) {
        if (spt[r][j]) {
          r = spt[r][j], rem -= (1 << j);
        } else {
          good = 0; break;
        }
      }
    }
    if (good) {
      pr.emplace_back(l, r);
      // cout << l << " " << r << endl;
    }
  }
  // cout << "yo\n";
  sort(pr.begin(), pr.end());
  sz = pr.size();
  for (int i = 0; i < sz; ++i) {
    lt.push_back(pr[i].first);
    rt.push_back(pr[i].second);
  }
  if (sz > 0) {
    for (int i = 0; i < sz; ++i) {
      t[sz + i] = rt[i];
    }
    for (int i = sz - 1; i > 0; --i) {
      t[i] = min(t[i << 1], t[i << 1 | 1]);
    }
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (sz == 0) {
      putchar('0');
    } else {
      int lb = lower_bound(lt.begin(), lt.end(), l) - lt.begin();
      int rb = upper_bound(lt.begin(), lt.end(), r) - lt.begin();
      if (query(lb, rb) <= r) putchar('1');
      else putchar('0');
    }
  }
  puts("");
  return 0;
}