// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

const int N = 200005;

int n, m[N], k[N];

int cnt[N], id[N];

double ansc = -1;
int anst;
vector<int> answho;

double cnt2[N];

void sol1() {
  rep(i, 1, n) cnt[m[i]]++;
  iota(id + 1, id + 200001, 1);
  sort(id + 1, id + 200001, [&](int x, int y) {
    return cnt[x] > cnt[y];
  });
  int pre = 0, op;
  rep(i, 1, 200000) {
    pre += cnt[id[i]];
    double resc = pre / 1. / max(20, i);
    if (resc >= ansc) ansc = resc, op = i;
  }
  anst = max(20, op);
  for (int i = 1; i <= op; i++) answho.pb(id[i]);
}

int main() {
  n = read();
  rep(i, 1, n) m[i] = read(), k[i] = read();
  // k > 20
//   sol1();
  // k <= 20
  rep(t, 1, 20) {
    rep(i, 1, 200000) cnt2[i] = 0, id[i] = i;
    rep(i, 1, n) {
      if (k[i] >= t) cnt2[m[i]] += 1;
      else cnt2[m[i]] += k[i] / 1. / t;
    }
    nth_element(id + 1, id + t, id + 200001, [&](int x, int y) {
      return cnt2[x] > cnt2[y];
    });
    double su = 0;
    rep(i, 1, t) {
      su += cnt2[id[i]];
    }
    if (su >= ansc) {
      ansc = su;
      anst = t;
      answho.clear();
      for (int i = 1; i <= t; i++) answho.pb(id[i]); 
    } 
  }
  printf("%d\n", anst);
  for (auto v: answho) printf("%d ", v);
  puts("");
  return 0;
}