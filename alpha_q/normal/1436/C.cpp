#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;
const int MOD = 1e9 + 7;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int n, x, pos;
ll fac[N], inv[N];
bool smol[N], big[N];

void fuck (int l = 0, int r = n) {
  if (l == r) return;
  int mid = l + r >> 1;
  if (pos + 1 <= mid) big[mid] = 1, fuck(l, mid);
  else smol[mid] = 1, fuck(mid + 1, r);
}

inline ll perm (int x, int y) {
  return fac[x] * inv[x - y] % MOD;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = i * fac[i - 1] % MOD;
    inv[i] = bigMod(fac[i], -1);
  }
  cin >> n >> x >> pos; 
  fuck();
  if (big[pos]) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (smol[i] and big[i]) {
      cout << "0\n";
      return 0;
    }
  }
  int smolCnt = 0, bigCnt = 0;
  for (int i = 0; i < n; ++i) if (i ^ pos) {
    if (smol[i]) ++smolCnt;
    if (big[i]) ++bigCnt;
  }
  if (smolCnt > x - 1 or bigCnt > n - x) {
    cout << "0\n";
    return 0;
  }
  ll ans = perm(x - 1, smolCnt) * perm(n - x, bigCnt) % MOD;
  ans = ans * fac[n - 1 - smolCnt - bigCnt] % MOD;
  cout << ans << '\n';
  return 0;
}



// n = 20

// [0, 20] ~ 10   --> [0, 10], [11, 20]
// [0, 10] ~ 5    --> [0, 5],  [6, 10]
// [11, 20] ~ 15  --> [11, 15], [16, 20]


// [l, r] ~ mid 

// a[mid] > x