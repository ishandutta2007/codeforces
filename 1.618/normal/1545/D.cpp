/*
start thinking:
BULB:
result of thinking: Lost.

 m  k .
, , ,  k 
,  shuffle, .  O(1) !
 rand,  k , .
 m  k , ,
 remake.
 m = 1000, k = 7  TLE ,  m 
 k !
 k  k , .
 ( exact cover) ? ,  NPC , .
.
 record , : sum x  sum x^2.
 sum x , .

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

#define maxk 1005
#define maxm 1005
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int myrand(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}

int m, k, y;
ll s1[maxk], s2[maxk], d1, d2;

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &m, &k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);
      s1[i] += x;
      s2[i] += (ll)x * x;
    }
  }
  for (int i = 1; i + 1 < k; i++) {
    if (s1[i + 1] - s1[i] == s1[i] - s1[i - 1])
      d1 = s1[i + 1] - s1[i];
  }
  for (int i = 1; i < k; i++) {
    if (s1[i] - s1[i - 1] != d1) {
      y = i;
      break;
    }
  }
  if (y == 1 && s1[2] - s1[1] == d1)
    y = 0;
  for (int i = 1; i + 1 < k; i++) {
    if (i - 1 != y && i != y && i + 1 != y) {
      d2 = 2 * s2[i] - s2[i - 1] - s2[i + 1];
      break;
    }
  }
  if (y == 0) {
    d1 = s1[1] - d1 - s1[0];
  } else {
    d1 = s1[y - 1] + d1 - s1[y];
  }
  if (y == 0) {
    d2 = 2 * s2[1] - s2[2] - d2 - s2[0];
  } else if (y == k - 1) {
    d2 = 2 * s2[k - 2] - s2[k - 3] - d2 - s2[k - 1];
  } else {
    d2 = (d2 + s2[y - 1] + s2[y + 1]) / 2 - s2[y];
  }
  printf("%d %lld\n", y, (d2 / d1 + d1) / 2);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}