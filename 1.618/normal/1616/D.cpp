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

#define int ll
#define maxn 50005
int n, a[maxn], sum[maxn], x, maxi[maxn], f[maxn];

void solve() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
  }
  scanf("%lld", &x);
  if (n == 1) {
    puts("1");
    return;
  }
  for (int i = 1; i <= n; i++) {
    a[i] -= x;
    sum[i] = sum[i - 1] + a[i];
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << sum[i] << " ";
  // }
  // cout << endl;
  // system("pause");

  vector<Pll> foo;
  for (int i = 0; i <= n; i++) {
    foo.push_back(mp(sum[i], i));
  }
  sort(foo.begin(), foo.end(), greater<Pll>());
  set<int> on;
  on.insert(-1);
  for (auto p : foo) {
    maxi[p.second] = p.second - *(--on.lower_bound(p.second - 1)) - 1;
    on.insert(p.second);
  }
  for (int i = 2; i <= n; i++) {
    chmin(maxi[i], maxi[i - 1] + 1);
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << maxi[i] << " ";
  // }
  // cout << endl;
  // system("pause");
  
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (maxi[i] == i) {
      f[i] = i;
    } else {
      f[i] = f[i - maxi[i] - 1] + maxi[i];
    }
  }
  printf("%lld\n", f[n]);
}

signed main() {
  int t;
  scanf("%lld", &t);
  while (t--)
    solve();
  return 0;
}