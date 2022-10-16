// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
 
inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
 
#define random(l, r) (rand() + 1) * (rand() + 1) % (r - l + 1) + l 
const int N = 200005;
long long a[N];
int vis[N], n;
 
set <long long> s;
void sieve(long long x) {
  if (x < 1) return ;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      s.insert(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    s.insert(x);
  }
}
 
long long ans = 0;
long long check(long long x) {
  long long ret = 0;
  for (rint i = 1; i <= n; i++) {
    if (a[i] <= x) ret += x - a[i];
    else ret += min(a[i] % x, x - a[i] % x);
    if (ret >= ans) return ans; 
  }
  return ret;
}
 
int main() {
  long long fuck = 0; // hack 
  scanf("%d", &n);
  for (rint i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    srand(i);
    fuck += a[i];
    if (rand() % 2) fuck--;
  }
  srand(time(NULL) + fuck);
  /*
  sort(a + 1, a + n + 1, greater <int> ());
  while (1) {
    static int pp = 0;
    pp++; if (pp >= 10) break;
    int idl = random(1, n - 1);
    int idr = random(idl + 1, n);
    sort(a + idl, a + idr + 1);
  }
  */
  //random_shuffle(a + 1, a + n + 1);
  ans = n;
  while (1) {
    static int ch = 0;
    ch++; if (ch > n || ch >= 300) break;  
    int id = random(1, n);
    while (vis[id]) id = random(1, n), id = random(1, n);
    vis[id] = 1;
    sieve(a[id] - 1), sieve(a[id]), sieve(a[id] + 1);
  }
  for (auto v: s) {
    ans = min(ans, check(v));
  }
  printf("%lld\n", ans);
  return 0;
}
 //