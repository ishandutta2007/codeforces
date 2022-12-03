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
  int n;
  scanf("%d", &n);
  if (n & 1) {
    puts("Bob");
    return;
  }
  if (__builtin_popcount(n) > 1) {
    puts("Alice");
    return;
  }
  if (__builtin_ctz(n) & 1) {
    puts("Bob");
    return;
  }
  puts("Alice");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  cerr << "did not RE" << endl;
  return 0;
}