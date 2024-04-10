/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
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
ll x;
multiset<ll> S;

void solve() {
  S.clear();
  scanf("%d%lld", &n, &x);
  for (int i = 1; i <= n; i++) {
    ll a;
    scanf("%lld", &a);
    S.insert(a);
  }
  int ans = 0;
  while (S.size()) {
    ll a = *S.begin();
    if (S.count(a * x)) {
      S.erase(S.begin());
      S.erase(S.find(a * x));
    } else {
      S.erase(S.begin());
      ans++;
    }
  }
  printf("%d\n", ans);
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