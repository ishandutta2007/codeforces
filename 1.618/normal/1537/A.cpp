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

void solve() {
  int n, sum = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    sum += a;
  }
  if (sum == n)
    puts("0");
  else
    printf("%d\n", max(sum - n, 1));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "did not RE" << endl;
  return 0;
}