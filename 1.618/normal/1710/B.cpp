/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n;
ll m, a[maxn];
tuple<ll, ll, int> rain[maxn];
bool ok[maxn];

void solve() {
  scanf("%d%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    a[i] = 0, ok[i] = 1;
    scanf("%lld%lld", &get<0>(rain[i]), &get<1>(rain[i]));
    get<2>(rain[i]) = i;
  }
  sort(rain + 1, rain + n + 1);
  ll sump = 0, sumx = 0;
  set<Pll> foo;
  for (int i = 1; i <= n; i++) {

    // cout << get<0>(rain[i]) << " " << get<1>(rain[i]) << endl;
    // system("pause");

    while (foo.size() && foo.begin()->first <= get<0>(rain[i])) {
      sump -= get<1>(rain[foo.begin()->second]);
      sumx -= get<0>(rain[foo.begin()->second]);
      foo.erase(foo.begin());
    }
    foo.insert({get<0>(rain[i]) + get<1>(rain[i]), i});
    sump += get<1>(rain[i]);
    sumx += get<0>(rain[i]);
    a[i] = sump - (foo.size() * get<0>(rain[i]) - sumx);
  }

  // for (int i = 1; i <= n; i++)
  //   cout << a[i] << " ";
  // cout << endl;
  // system("pause");

  foo.clear(); sump = sumx = 0;
  for (int i = n; i >= 1; i--) {
    while (foo.size() && foo.rbegin()->first >= get<0>(rain[i])) {
      sump -= get<1>(rain[foo.rbegin()->second]);
      sumx -= get<0>(rain[foo.rbegin()->second]);
      foo.erase(--foo.end());
    }

    // cout << sump << " " << sumx << endl;
    // system("pause");

    a[i] += sump - (sumx - foo.size() * get<0>(rain[i]));
    foo.insert({get<0>(rain[i]) - get<1>(rain[i]), i});
    sump += get<1>(rain[i]);
    sumx += get<0>(rain[i]);
  }

  // for (int i = 1; i <= n; i++)
  //   cout << a[i] << " ";
  // cout << endl;
  // system("pause");

  ll maxi = -infll;
  for (int i = 1; i <= n; i++) {
    if (a[i] > m) {
      chmax(maxi, a[i] - m - get<0>(rain[i]));
    }
    if (maxi + get<0>(rain[i]) > get<1>(rain[i]))
      ok[get<2>(rain[i])] = false;
  }
  maxi = -infll;
  for (int i = n; i >= 1; i--) {
    if (a[i] > m) {
      chmax(maxi, a[i] - m + get<0>(rain[i]));
    }
    if (maxi - get<0>(rain[i]) > get<1>(rain[i]))
      ok[get<2>(rain[i])] = false;
  }
  for (int i = 1; i <= n; i++) {
    printf("%c", "01"[ok[i]]);
  }
  puts("");
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}