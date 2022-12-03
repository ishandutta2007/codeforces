/*
start thinking:
BULB:
result of thinking: Aided. .

 cnt0 = cnt1 , .
 1  0, 1  +1, 0  -1 , ,
: , .
, !
, .
 O(n).

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

#define maxn 200005
int n, h[maxn];
char s[maxn];
vector<int> pos[maxn];

void solve() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  if (count(s + 1, s + n + 1, '0') * 2 > n) {
    for (int i = 1; i <= n; i++)
      s[i] = '0' + '1' - s[i];
    reverse(s + 1, s + n + 1);
  }
  for (int i = 0; i <= n; i++)
    pos[i].clear();
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] + (s[i] == '0' ? -1 : 1);
    if (h[i] >= 0)
      pos[h[i]].push_back(i);
  }
  int p = n;
  while (p && h[p - 1] < h[p])
    p--;
  if (h[p] == -p) {
    puts("0");
    return;
  }
  int ans = 1, hei = h[p];
  while (hei > 0) {
    int foo = pos[hei].front();
    hei -= (n - (h[n] - hei) - foo) / 2;
    ans++;
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
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}