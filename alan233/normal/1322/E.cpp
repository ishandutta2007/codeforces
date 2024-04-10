// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 500005;
vector<int> pos[N];
int a[N], b[N], state[N], ans[N], tim[N], type, n, m;
int anss;
set<int> alive, same; 

void cov(int l, int r, int x) {
  while (true) {
    auto it = alive.lower_bound(l);
    if (it == alive.end() || (*it) > r) break;
    ans[*it] = x;
    alive.erase(it);
  }
}
void update(int ps, int x) {
//  printf("update %d %d\n", ps, x); 
  auto it = same.upper_bound(ps);
  int R = (*it) - 1;
  int L = *prev(it);
  anss = max(anss, (R - L) / 2);
  if (state[L] == state[R]) {
    if (!state[L]) cov(L, R, x);
  } else {
    int mid = L + R >> 1;
    if (!state[L]) cov(L, mid, x);
    else cov(mid + 1, R, x);
  }
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), b[i] = a[i];
  sort(b + 1, b + n + 1), m = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
    pos[a[i]].pb(i);
  }
  for (int i = 1; i <= n; i++) {
    state[i] = 1;
    alive.insert(i);
  }
  for (int i = 1; i <= n + 1; i++) same.insert(i);
  for (int i = 1; i <= m; i++) {
    for (auto v: pos[i]) {
      state[v] ^= 1;
      if (v > 1) {
        if (state[v] == state[v - 1]) same.insert(v);
        else same.erase(v);
      }
      if (v < n) {
        if (state[v + 1] == state[v]) same.insert(v + 1);
        else same.erase(v + 1);
      }
    }
    for (auto v: pos[i]) {
//      printf("??\n");
      for (int ps = v - 1; ps <= v + 1; ps++) {
        if (ps >= 1 && ps <= n && tim[ps] != i) {
          tim[ps] = i;
          update(ps, i);
        } 
      }
    }
  }
  printf("%d\n", anss);
  for (int i = 1; i <= n; i++) printf("%d ", b[ans[i]]);
  puts("");
  return 0;
}