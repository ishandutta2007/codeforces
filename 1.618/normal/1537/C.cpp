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

#define maxn 200005
const int inf = 0x3f3f3f3f;
int n, h[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", h + i);
  sort(h + 1, h + n + 1);
  int minDif = h[n] - h[1], pos = 0;
  for (int i = 1; i < n; i++) {
    if (chmin(minDif, h[i + 1] - h[i]))
      pos = i;
  }
  for (int i = pos + 1; i <= n; i++)
    printf("%d ", h[i]);
  for (int i = 1; i <= pos; i++)
    printf("%d ", h[i], i == pos ? '\n' : ' ');
  puts("");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "did not RE" << endl;
  return 0;
}