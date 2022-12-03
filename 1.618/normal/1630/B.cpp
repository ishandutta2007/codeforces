/*
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
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
int n, a[maxn], k, cnt[maxn];

void go(int x, int y) {
  printf("%d %d\n", x, y);
  int foo = 0, lst = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= x && a[i] <= y)
      foo++;
    else
      foo--;
    if (foo > 0) {
      cnt++;
      if (cnt == k) {
        printf("%d %d\n", lst + 1, n);
        return;
      }
      printf("%d %d\n", lst + 1, i);
      lst = i;
      foo = 0;
    }
  }
}

void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    cnt[i] = 0;
  int x = 1, y = n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++)
    cnt[i] += cnt[i - 1];
  
  // for (int i = 1; i <= n; i++) {
  //   cout << cnt[i] << " ";
  // }
  // cout << endl;

  for (int i = 1, j = 0; i <= n; i++) {
    while (j <= n && 2 * (cnt[j] - cnt[i - 1]) - n < k)
      j++;
    if (j > n)
      break;
    
    // cout << i << " " << j << endl;
    // system("pause");

    if (j - i < y - x)
      x = i, y = j;
    
    // cout << x << " " << y << endl;
    // system("pause");

  }
  go(x, y);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
/*
1
11 3
5 5 5 1 5 5 1 5 5 5 1
*/