/*
start thinking:
BULB:
result of thinking: Lost.

seq, len = k
  initial_inv - C(k, 2) - (sum_{i \in seq} dec(i) - 2 * inv_within_seq)
dec(i)p[i].
f[i] = (p[i]>) - (p[i]<) - 2 * (p[i]<) .

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
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 500005
int n, bit[maxn], f[maxn];

void add(int pos, int x) {
  for (int i = pos; i <= n; i += i & -i)
    bit[i] += x;
}
int qsum(int pos) {
  int res = 0;
  for (int i = pos; i; i -= i & -i)
    res += bit[i];
  return res;
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    bit[i] = 0;
  ll inv0 = 0;
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d", &p);
    add(p, 1);
    inv0 += i - qsum(p);
    f[i] = i - 1 - 2 * (p - 1);
  }
  sort(f + 1, f + n + 1, greater<int>());
  printf("%lld ", inv0);
  for (int i = 1; i <= n; i++) {
    inv0 -= f[i];
    printf("%lld ", inv0 - (ll)i * (i - 1) / 2);
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
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}