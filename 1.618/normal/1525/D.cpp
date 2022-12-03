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

#define maxn 5005
int n, a[maxn], f[maxn], minf[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (!a[i])
      chmin(f[i], f[i - 1]);
    vector<int> fre, occ;
    int w = 0;
    for (int j = i; j >= 1; j--) {
      if (a[j]) {
        if (fre.size()) {
          w += fre.back() - j;
          fre.pop_back();
        } else {
          occ.push_back(j);
        }
      } else {
        if (occ.size()) {
          w += occ.back() - j;
          occ.pop_back();
        } else {
          fre.push_back(j);
        }
      }
      if (fre.empty() && occ.empty()) {
        chmin(f[i], f[j - 1] + w);
        break;
      }
    }
  }
  printf("%d\n", f[n]);
  return 0;
}