/*
result of thinking: Lost.

 /kk
x "x S x" (xS), |S|
"~S S x S x" (~S = reverse(S.begin(), S.end())).
xO(n).
# 
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

int n;
map<int, int> cnt;
vector<int> a;
vector<P> oprs;
vector<int> lens;

void go() {
  int m = a.size(), x = m - 2;
  while (a[x] != a[m - 1])
    x--;
  vector<int> foo;
  for (int i = m - 2; i > x; i--) {
    oprs.push_back({x + (m - 2) - i, a[i]});
    foo.push_back(a[i]);
  }
  lens.push_back(2 * (m - 1 - x));
  for (int i = m - 1; i >= x; i--)
    a.pop_back();
  for (auto i : foo)
    a.push_back(i);
}

void solve() {
  cnt.clear();
  oprs.clear();
  lens.clear();
  scanf("%d", &n);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  for (auto i : cnt) {
    if (i.second & 1) {
      puts("-1");
      return;
    }
  }
  while (a.size())
    go();
  printf("%d\n", int(oprs.size()));
  for (auto i : oprs) {
    printf("%d %d\n", i.first, i.second);
  }
  reverse(lens.begin(), lens.end());
  printf("%d\n", int(lens.size()));
  for (auto i : lens) {
    printf("%d ", i);
  }
  puts("");
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}