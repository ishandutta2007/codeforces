/*


Q.E.D.

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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 500005
const ull B = 23333;

int n, k;
char s[maxn];
ull powB[maxn], hsh[maxn];

ull powBsum(int x, int y) { // 1 + B^x + ... + B^(y*x)
  if (y < 0)
    return 0;
  if (!y)
    return 1;
  if (y == 1)
    return 1 + powB[x];
  int yy = y / 2;
  ull res = powBsum(x, yy) * (1 + powB[(yy + 1) * x]);
  if (!(y & 1))
    res -= powB[(y + 1) * x];
  return res;
}

ull calcHsh(int len, int pos) {
  int t = (len - 1) / pos;
  len = (len - 1) % pos + 1;
  return powBsum(pos, t - 1) * hsh[pos] + hsh[len] * powB[t * pos];
}

int main() {
  powB[0] = 1;
  for (int i = 1; i <= 500000; i++)
    powB[i] = powB[i - 1] * B;
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  while (n < k) 
    s[++n] = '~';
  int opt = 1;
  hsh[1] = B * s[1];
  for (int i = 2; i <= n; i++) {
    hsh[i] = hsh[i - 1] + powB[i] * s[i];
    int lb = 0, rb = n;
    while (lb < rb) {
      int mid = (lb + rb + 1) >> 1;
      if (calcHsh(mid, opt) == calcHsh(mid, i))
        lb = mid;
      else
        rb = mid - 1;
    }
    if (s[lb % opt + 1] > s[lb % i + 1])
      opt = i;
  }
  for (int i = 1; i <= k; i++)
    printf("%c", s[(i - 1) % opt + 1]);
  puts("");
  return 0;
}