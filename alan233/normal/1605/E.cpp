// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 200005;

struct Info {
  ll A, B;
} a[N], b[N];

ll preaA[N], preaB[N];
ll prebA[N], prebB[N];
ll sufaA[N], sufaB[N];
ll sufbA[N], sufbB[N];

ll A[N], B[N]; // A[i] * x + B[i]
int n, m1, m2, q, aa[N], bb[N];

int main() {
  n = read();
  rep(i, 1, n) aa[i] = read();
  rep(i, 1, n) bb[i] = read();
  rep(i, 2, n) B[i] = bb[i] - aa[i];
  A[1] = 1, B[1] = -aa[1];
  for (int i = 2; i <= n; i++) A[i] -= A[1], B[i] -= B[1];
  rep(i, 2, n) {
    for (int j = 2 * i; j <= n; j += i) A[j] -= A[i], B[j] -= B[i];
  }
  /*
  rep(i, 1, n) {
    printf("A[%d] = %lld, B[%d] = %lld\n", i, A[i], i, B[i]);
  }
  */
  ll preans = 0;
  m1 = m2 = 0;
  rep(i, 1, n) {
    if (A[i] == 0) preans += llabs(B[i]);
    else if (A[i] > 0) {
      a[++m1] = {A[i], B[i]};
    } else {
      b[++m2] = {A[i], B[i]};
    }
  }
  sort(a + 1, a + m1 + 1, [&](Info a, Info b) {
    return (__int128)a.B * b.A > (__int128)b.B * a.A;
  });
  sort(b + 1, b + m2 + 1, [&](Info a, Info b) {
    return (__int128)a.B * b.A > (__int128)b.B * a.A;
  });
  rep(i, 1, m1) {
    preaA[i] = preaA[i - 1] + a[i].A;
    preaB[i] = preaB[i - 1] + a[i].B;
  }
  per(i, m1, 1) {
    sufaA[i] = sufaA[i + 1] + a[i].A;
    sufaB[i] = sufaB[i + 1] + a[i].B;
  }
  rep(i, 1, m2) {
    prebA[i] = prebA[i - 1] + b[i].A;
    prebB[i] = prebB[i - 1] + b[i].B;
  }
  per(i, m2, 1) {
    sufbA[i] = sufbA[i + 1] + b[i].A;
    sufbB[i] = sufbB[i + 1] + b[i].B;
  }
/*
  printf("m1 = %d, m2 = %d\n", m1, m2);
  rep(i, 1, m1) printf("(%lld, %lld), ", a[i].A, a[i].B); puts("");
  rep(i, 1, m2) printf("(%lld, %lld), ", b[i].A, b[i].B); puts("");
*/
  q = read();
  while (q--) {
    int x = read();
    ll ans = preans;
    /*
    rep(i, 1, n) ans += llabs(1ll * A[i] * x + B[i]);
    */
    int l = 0, r = m1;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (-a[mid].B >= x * a[mid].A) r = mid - 1;
      else l = mid;
    }
    // printf("l = %d\n", l);
    ans += (preaA[l] * x + preaB[l]) - (sufaA[l + 1] * x + sufaB[l + 1]);
    // printf("now ans = %lld\n", ans);
    l = 0, r = m2;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (-b[mid].B <= b[mid].A * x) r = mid - 1;
      else l = mid;
    }
    // printf("l = %d\n", l);
    ans += -(prebA[l] * x + prebB[l]) + (sufbA[l + 1] * x + sufbB[l + 1]);
    print(ans, '\n');
  }
  return 0;
}