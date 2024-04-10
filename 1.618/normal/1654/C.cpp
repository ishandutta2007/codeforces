/*
start thinking:
BULB:
result of thinking:

start coding:
AC:

TLE: multiset::countO(n)!
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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

bool solve() {
  int n;
  scanf("%d", &n);
  multiset<ll> tar;
  priority_queue<ll> cur;
  ll s = 0;
  for (int i = 1; i <= n; i++) {
    ll a;
    scanf("%lld", &a);
    tar.insert(a);
    s += a;
  }
  if (n == 1)
    return true;
  cur.push(s);
  while (cur.size()) {
    auto u = cur.top(), u1 = u / 2, u2 = u - u / 2;
    if (u < *tar.rbegin())
      return false;
    cur.pop();
    auto it = tar.find(u1);
    if (it != tar.end()) {
      tar.erase(it);
    } else {
      cur.push(u1);
    }
    it = tar.find(u2);
    if (it != tar.end()) {
      tar.erase(it);
    } else {
      cur.push(u2);
    }
    if (cur.size() > tar.size())
      return false;
  }
  return true;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    puts(solve() ? "YES" : "NO");
  return 0;
}