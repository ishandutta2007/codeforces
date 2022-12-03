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
const int inf = 0x3f3f3f3f;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

bool solve() {
  vector<int> o, e, t;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    if (i & 1)
      o.push_back(a);
    else
      e.push_back(a);
  }
  sort(o.begin(), o.end(), greater<int>());
  sort(e.begin(), e.end(), greater<int>());
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      t.push_back(o.back());
      o.pop_back();
    } else {
      t.push_back(e.back());
      e.pop_back();
    }
  }
  for (int i = 1; i < n; i++) 
    if (t[i] < t[i - 1])
      return false;
  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    puts(solve() ? "Yes" : "No");
  cerr << "did not RE" << endl;
  return 0;
}