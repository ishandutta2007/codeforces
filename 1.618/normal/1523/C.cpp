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
  vector<int> cur;
  while (n--) {
    int a;
    scanf("%d", &a);
    if (a == 1)
      cur.push_back(1);
    else {
      while (cur.back() + 1 != a)
        cur.pop_back();
      cur[cur.size() - 1]++;
    }
    for (int i = 0; i < (int)cur.size() - 1; i++)
      printf("%d.", cur[i]);
    printf("%d\n", cur.back());
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}