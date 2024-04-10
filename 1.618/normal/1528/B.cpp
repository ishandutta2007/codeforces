/*


Q.E.D.

start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 1000005
const int mod = 998244353;
int n, d[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      d[j]++;
    }
  }
  int f = 1, s = 1;
  for (int i = 2; i <= n; i++) {
    f = (s + d[i]) % mod;
    (s += f) %= mod;
  }
  printf("%d\n", f); 
  return 0;
}