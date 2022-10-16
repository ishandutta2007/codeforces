// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

int n, k;
int pos1, val1, pos2, val2, cnt1, cnt2;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k + 1; i++) {
    printf("? ");
    for (int j = 1; j <= k + 1; j++) {
      if (j != i) printf("%d ", j);
    }
    puts(""), fflush(stdout);
    int pos, val;
    scanf("%d%d", &pos, &val);
    if (!pos1 || pos1 == pos) pos1 = pos, val1 = val, cnt1++;
    else pos2 = pos, val2 = val, cnt2++;
  }
  if (val1 > val2) printf("! %d\n", cnt1);
  else printf("! %d\n", cnt2);
  fflush(stdout);
  return 0;
}