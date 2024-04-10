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

const int N = 1005;
ll sum1[N], sum2[N];
int m, k;

ll Sum1;
int pos;
void calc1() {
  ll res = 0, beat = 0;
  rep(i, 2, k) {
    if (sum1[i] - sum1[i - 1] != res) beat--; else beat++;
    if (beat < 0) res = sum1[i] - sum1[i - 1], beat = 0;
  }
  Sum1 = res;
  rep(i, 2, k - 1) {
    if (sum1[i + 1] - sum1[i] != res && sum1[i] - sum1[i - 1] != res) {
      pos = i;
      break;
    }
  }
//  if (!pos) {
//    if (sum1[2] - sum1[1] != res) pos = 1;
//    if (sum1[k] - sum1[k - 1] != res) pos = k;
//  }
}
ll Sum2;
void calc2() {
  ll res = 0, beat = 0;
  rep(i, 2, k - 1) {
    ll t = (sum2[i - 1] + sum2[i + 1] - 2 * sum2[i]) / 2;
//    printf("%lld\n",t);
//    if (t != res) beat--; else beat++;
//    if (beat < 0) res = t, beat = 0;
    if (i - 1 <= pos && pos <= i + 1) ;
    else Sum2 = t;
  }
}

int main() {
  m = read(), k = read();
  rep(i, 1, k) {
    rep(j, 1, m) {
      int x = read();
      sum1[i] += x, sum2[i] += 1ll * x * x;
    }
//    cerr << i << ": " << sum1[i] << " " << sum2[i] << '\n';
  }
  calc1();
  printf("%d ", pos - 1); 
  calc2();
//  cerr << "sum = " << Sum1 << " " << Sum2 << '\n';
  ll zz = sum2[pos] - (sum2[pos - 1] + sum2[pos + 1] - 2 * Sum2) / 2;
  ll dlt = (sum1[pos] - sum1[pos - 1]) - Sum1;
  ll x = (zz - dlt * dlt) / 2 / dlt;
//  printf("zz = %lld, dlt = %lld, x = %lld\n", zz, dlt, x);
  printf("%lld\n", x);
  return 0;
}