#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500010;

struct node {
  int minVal, minCnt;

  node () {}
  node (int mn, int cnt) {
    minVal = mn, minCnt = cnt;
  }

  node operator + (const node oth) const {
    node ret(minVal, minCnt);
    if (oth.minVal < ret.minVal) ret = oth;
    else if (oth.minVal == ret.minVal) ret.minCnt += oth.minCnt;
    return ret;
  }
};

node t[N << 2];
vector <int> occ[N];
int n, a[N], lazy[N << 2];

void init (int u = 1, int b = 1, int e = n) {
  lazy[u] = 0;
  if (b == e) return void(t[u] = node(0, 1));
  int mid = b + e >> 1;
  init(u << 1, b, mid), init(u << 1 | 1, mid + 1, e);
  t[u] = t[u << 1] + t[u << 1 | 1];
}

inline void push (int u, int b, int e) {
  t[u].minVal += lazy[u];
  if (b ^ e) lazy[u << 1] += lazy[u], lazy[u << 1 | 1] += lazy[u];
  lazy[u] = 0;
}

void update (int l, int r, int v, int u = 1, int b = 1, int e = n) {
  if (lazy[u]) push(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lazy[u] += v;
    return push(u, b, e);
  }
  int mid = b + e >> 1;
  update(l, r, v, u << 1, b, mid), update(l, r, v, u << 1 | 1, mid + 1, e);
  t[u] = t[u << 1] + t[u << 1 | 1];
}

node query (int l, int r, int u = 1, int b = 1, int e = n) {
  if (b > r or e < l) return node(INT_MAX, 0);
  if (lazy[u]) push(u, b, e);
  if (b >= l and e <= r) return t[u];
  int mid = b + e >> 1;
  return query(l, r, u << 1, b, mid) + query(l, r, u << 1 | 1, mid + 1, e);
}

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> n; init();
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    vector <int> &vec = occ[a[i]];
    int sz = vec.size();
    if (sz) {
      int lt, rt;
      rt = vec.back();
      lt = (sz < 3) ? 1 : (vec[sz - 3] + 1);
      if (lt <= rt) update(lt, rt, -1);
      if (sz >= 4) {
        lt = 1, rt = vec[sz - 4];
        if (lt <= rt) update(lt, rt, -1);
      }
    }
    vec.emplace_back(i); ++sz;
    int lt, rt;
    rt = vec.back();
    lt = (sz < 3) ? 1 : (vec[sz - 3] + 1);
    if (lt <= rt) update(lt, rt, +1);
    if (sz >= 4) {
      lt = 1, rt = vec[sz - 4];
      if (lt <= rt) update(lt, rt, +1);
    }
    node yo = query(1, i);
    if (yo.minVal == 0) ans += yo.minCnt;
  }
  cout << ans << '\n';
  return 0;
}