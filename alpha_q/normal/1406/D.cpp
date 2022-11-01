#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;
const ll INF = 1e16 + 69;

int n, q;
ll a[N], d[N], f[N];

void update (int p, ll v) {
  while (p < N) f[p] += v, p += p & -p;
}

ll get (int p) {
  ll ret = 0;
  while (p) ret += f[p], p -= p & -p;
  return ret;
}

ll solve() {
  ll one = get(n), two = a[1];
  if (one > two) swap(one, two);
  return two - (two - one) / 2;  
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  a[n + 1] = -INF;
  for (int i = 1; i <= n; ++i) {
    d[i] = a[i + 1] - a[i];
    update(i, max(0LL, d[i]));
  }
  printf("%lld\n", solve());
  cin >> q;
  while (q--) {
    int l, r; ll x;
    scanf("%d %d %lld", &l, &r, &x);
    if (l == 1) {
      a[1] += x;
    }
    if (l > 1) {
      ll off = -max(0LL, d[l - 1]);
      d[l - 1] += x;
      off += max(0LL, d[l - 1]);
      update(l - 1, off);
    }
    if (r < n) {
      ll off = -max(0LL, d[r]);
      d[r] -= x;
      off += max(0LL, d[r]);
      update(r, off);
    }
    printf("%lld\n", solve());
  }
  return 0;
}

// b[1] <= b[2] <= ... <= b[n]
// c[1] - b[1] >= c[2] - b[2] >= ... >= c[n] - b[n]

// c[i] - b[i] >= c[i+1] - b[i+1]

// b[i] <= b[i+1] + c[i]-c[i+1]


// max(0, c[i+1]-c[i])


// max(b[n], a[1]-b[1])


// b[1]=0, b[2]=
// 2, -1, 7, 3

// 0, 0, 8, 8
// 2, -1, -1, -5


// sum-x, a[1]+x


// sum-x = a[1]+x

// a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]