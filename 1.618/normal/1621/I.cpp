/*
start thinking:
BULB:
result of thinking: Lost.

part2...
part1:
:
  - ia[i] < a[i + 1] or i = n, a[i + 1 : n]a[i] (1)
iop.
B_6 = B_7 = B_8 = ...5op (B_6(1))
op.
part2:
Slexmin.
part3:
a[1:r], lexminS = a[l:r], ka[k:r] = S,
n-r+1(i.e. argmin_{1<=i<=r} {a[i:i+n-r]})lk.
:
> But if the prefix of T of length |S| is larger than S, then it is incorrect...
Ta[r+1:]n-rla[r+1:].
> By the same reasons we can show that concatenation of k  |T|/|S| copies...
(k-1)STkT[(k-1)|S| + 1 : k|S|] > S, n-r-(k-1)|S|
la[r+(k-1)|S|+1:].
> If |T|mod|S|  0 then the suffix of S of length |T|mod|S| is lexsmaller than S...
TSSlexminS.
part4:
b_iO(i)a.

ecnerwalaopO(n):
aitransb_i
a[1, n - i] + a[p_i, n - i + 1] + ... + a[p_2, n - 1] + a[p_1, n]
1 <= p_j <= n - j + 1.
nb: a[p_i, n-i+1]a[1:n-i+1]
 iff p_{i - 1} = n - i + 2.
comment: https://codeforces.com/blog/entry/98654?#comment-874702
O(n)Slexmin, 
.
lyndonlyndonkmpborder.
duval!

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
template <class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template <class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005

// stk: current pre-simple, 0-base
// border: lyndon(1)
int n, b[7][maxn], border[maxn], stk[maxn], tp;
// (lyndonlyndon)
P res[maxn], ans[maxn];
// op
int pos[maxn];

void op(int *c, int *d) {
  tp = 0;
  border[0] = -1;
  for (int i = 1; i <= n; i++) {
    while (tp && c[i] < stk[border[tp]])
      tp %= tp - border[tp];
    if (!tp || c[i] == stk[border[tp]])
      border[tp + 1] = border[tp] + 1;
    else
      border[tp + 1] = 0;
    stk[tp++] = c[i];
    int foo = tp % (tp - border[tp]);
    if (!foo)
      res[tp] = {tp - border[tp], tp};
    else
      res[tp] = res[foo];
    // , c[1:i]lyndonans[i].
    ans[i] = res[tp];
  }
  pos[n] = n - ans[n].second + 1;
  for (int i = n - 1; i >= 1; i--)
    pos[i] = i - (pos[i + 1] == i + 1 ? ans[i].first : ans[i].second) + 1;
  int k = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = pos[i]; j <= i; j++) {
      d[++k] = c[j];
      if (k == n)
        return;
    }
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &b[0][i]);
  for (int i = 1; i <= 6; i++)
    op(b[i - 1], b[i]);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    chmin(x, 6);
    printf("%d\n", b[x][y]);
  }
  return 0;
}