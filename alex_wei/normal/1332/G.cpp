#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
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
constexpr int N = 2e5 + 5;
int n, q, a[N], in[N], lst[N], rt[N];
set<int> exist;
set<pii> query;
struct stack {
  int tp, stc[N];
  bool empty() {return !tp;}
  int top() {return stc[tp];}
  void pop() {
    int val = stc[tp--];
    if(!--in[val]) exist.insert(val);
  }
  void push(int val) {
    stc[++tp] = val;
    if(!in[val]++) exist.erase(val);
  }
  int binary(int val) {
    if(a[stc[1]] == a[val]) return n;
    int l = 1, r = tp;
    while(l < r) {
      int m = l + r + 2 >> 1;
      if(a[stc[m]] == a[val]) r = m - 1;
      else l = m;
    }
    return stc[l];
  }
  int pref(int val) {
    int l = 1, r = tp;
    while(l < r) {
      int m = l + r >> 1;
      if(stc[m] < val) r = m;
      else l = m + 1;
    }
    return stc[l];
  }
} mn, mx;
vector<int> ans[N];
vector<pii> buc[N];
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> q, lst[n + 1] = rt[n + 1] = n + 1;
  for(int i = 1; i <= n; i++) a[i] = read();
  for(int i = n; i; i--) {
    exist.insert(i);
    rt[i] = a[i] == a[i + 1] ? rt[i + 1] : i + 1;
    if(rt[i + 1] <= n && 1ll * (a[i + 1] - a[i]) * (a[i + 1] - a[rt[i + 1]]) > 0) lst[i] = i;
    else lst[i] = lst[i + 1];
  }
  exist.insert(n + 1);
  for(int i = 1; i <= q; i++) {
    int l = read(), r = read();
    if(lst[l] <= n && rt[lst[l] + 1] <= r) {
      ans[i].push_back(lst[l]);
      ans[i].push_back(lst[l] + 1);
      ans[i].push_back(rt[lst[l] + 1]);
    }
    if(r - l + 1 >= 4) {
      buc[r - 3].push_back({i, r});
      buc[l - 1].push_back({-i, r});
    }
  }
  for(int i = n; i; i--) {
    while(!mx.empty() && a[i] > a[mx.top()]) mx.pop();
    while(!mn.empty() && a[i] < a[mn.top()]) mn.pop();
    mx.push(i), mn.push(i);
    for(pii it : buc[i]) {
      int id = abs(it.first), r = it.second;
      if(it.first < 0) {
        auto pt = query.find({r, id});
        if(pt != query.end()) query.erase(pt);
      }
      else query.insert({r, id});
    }
    if(!query.empty()) {
      int pos = *exist.upper_bound(max(mn.binary(i), mx.binary(i)));
      if(pos > n) continue;
      while(!query.empty()) {
        auto pt = --query.end();
        if(pt->first >= pos) {
          int id = pt->second;
          ans[id].clear();
          ans[id].push_back(i);
          ans[id].push_back(mn.pref(pos));
          ans[id].push_back(mx.pref(pos));
          ans[id].push_back(pos);
          query.erase(pt);
        }
        else break;
      }
    }
  }
  for(int i = 1; i <= q; i++) {
    if(ans[i].size()) {
      putchar(ans[i].size() + '0'), putchar('\n');
      sort(ans[i].begin(), ans[i].end());
      for(int it : ans[i]) print(it), putchar(' ');
    }
    else putchar('0');
    putchar('\n');
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/16
author: Alex_Wei
start coding at 22:43
finish debugging at 23:46
*/