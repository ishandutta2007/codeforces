#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
inline ll read() {
  ll x = 0, sgn = 0;
  char s = getchar();
  while(!isdigit(s)) sgn |= s == '-', s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return sgn ? -x : x;
}
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 3e5 + 5;
int n, k;
vector<pii> laz[N], buc[N];
struct itv {
  int l, r, tag;
  bool operator < (const itv &x) const {
    return l ^ x.l ? l < x.l : r < x.r;
  }
};
set<itv> s;
void split(int p) {
  if(p == 0) return;
  auto pt = --s.upper_bound({p + 1, 0, 0});
  if(pt->r == p) return;
  s.insert({pt->l, p, pt->tag});
  s.insert({p + 1, pt->r, pt->tag});
  s.erase(pt);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> k;
  s.insert({1, 1000000000, 0});
  for(int i = 1; i <= n; i++) {
    int l = read(), r = read() - 1;
    split(l - 1), split(r);
    while(1) {
      auto pt = s.lower_bound({l, 0, 0});
      if(pt == s.end() || pt->l > r) break;
      int lst = pt->tag, len = pt->r - pt->l + 1;
      laz[i].push_back({lst + 1, len});
      laz[i].push_back({i + 1, -len});
      buc[lst + 1].push_back({i, len});
      buc[i + 1].push_back({i, -len});
      s.erase(pt);
    }
    s.insert({l, r, i});
    sort(laz[i].begin(), laz[i].end());
  }
  for(int i = 1; i <= n; i++) sort(buc[i].begin(), buc[i].end());
  int l = 1, r = 1e9;
  lll sum = 0, count = 0;
  while(l < r) {
    int m = l + r + 2 >> 1;
    sum = count = 0;
    ll csum = 0, cur = 0;
    for(int l = 1, r = 1; r <= n; r++) {
      for(auto it : laz[r]) {
        if(it.first > l) break;
        cur += it.second;
        csum += 1ll * it.second * (l - it.first);
      }
      while(cur >= m) {
        csum += cur, l++;
        for(auto it : buc[l]) {
          if(it.first > r) break;
          cur += it.second;
        }
      }
      count += l - 1, sum += csum;
    }
    if(count >= k) l = m;
    else r = m - 1;
  }
  cout << (ll) (sum - (count - k) * l) << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/26
author: Alex_Wei
start coding at 7:39
finish debugging at 8:54
*/