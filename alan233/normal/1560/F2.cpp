// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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

const int N = 25;
char a[N];
int len, k;

void solve() {
  scanf("%s%d", a + 1, &k);
  len = strlen(a + 1);
  rep(i, 1, len) a[i] ^= '0';
  ll ans = 1e18;
  ll __ = 0;
  if (k == 1) {
    rep(i, 1, len + 1) __ = 10ll * __ + 1;
  } else {
    __ = 1;
    rep(i, 2, len + 1) __ *= 10ll; 
  }
  ckmin(ans, __);
  set<int> nums;
  rep(i, 0, len) {
    if (i) nums.insert(a[i]);
    if (SZ(nums) > k || i == len) {
      break;
    }
    if (a[i + 1] == 9) continue;
    int t = a[i + 1];
    auto it = nums.lower_bound(t + 1);
    if (it == nums.end()) {
      if (SZ(nums) == k) continue;
    }
    set<int> num = nums;
    if (SZ(num) < k && !num.count(t + 1)) num.insert(t + 1);
    it = num.lower_bound(t + 1);
    int way = *it;
    ll _ = 0;
    rep(j, 1, i) _ = 10ll * _ + a[j];
    _ = 10ll * _ + way;
    if (SZ(num) < k) num.insert(0);
    it = num.begin();
    way = *it;
    rep(j, i + 2, len) _ = 10ll * _ + way;
    ckmin(ans, _); 
  }
  if (SZ(nums) <= k) {
    ll _ = 0;
    rep(i, 1, len) _ = 10ll * _ + a[i];
    ckmin(ans, _);
  }
  print(ans, '\n');
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}