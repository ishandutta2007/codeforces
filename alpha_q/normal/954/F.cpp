#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

void copy (ll a[3][3], ll b[3][3]) {
  for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
    b[i][j] = a[i][j];
  }
}

void mult (ll a[3][3], ll b[3][3], ll c[3][3]) {
  for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
    c[i][j] = 0;
    for (int k = 0; k < 3; ++k) c[i][j] += a[i][k] * b[k][j];
    c[i][j] %= MOD;
  }
}

vector <tuple <ll, int, int>> ev;
int n; ll m, cnt[3], ans[3][3], base[3][3], ret[3][3], tmp[3][3];

void expo (ll x) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) ret[i][j] = 0;
    ret[i][i] = 1;
  }
  while (x) {
    if (x & 1) mult(ret, base, tmp), copy(tmp, ret);
    mult(base, base, tmp), copy(tmp, base), x >>= 1;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int ro; ll l, r;
    scanf("%d %lld %lld", &ro, &l, &r);
    --ro, --l;
    ev.emplace_back(l, ro, +1);
    ev.emplace_back(r, ro, -1);
  }
  ev.emplace_back(1, 0, 0);
  ev.emplace_back(m - 1, 0, 0);
  sort(ev.begin(), ev.end());
  int last = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) ans[i][j] = 0;
    ans[i][i] = 1;
  }
  for (int i = 0, j = 0; i + 1 < ev.size(); i = j) {
    while (j + 1 < ev.size() and get<0>(ev[j]) == get<0>(ev[i])) {
      auto [co, ro, delta] = ev[j];
      cnt[ro] += delta, ++j;
    }
    ll fro = get<0>(ev[i]), to = get<0>(ev[j]);
    // cout << fro << " " << to << '\n';
    // for (int k = 0; k < 3; ++k) cout << !!cnt[k] << " "; cout << '\n';
    base[0][0] = !cnt[0], base[0][1] = !cnt[1], base[0][2] = 0;
    base[1][0] = !cnt[0], base[1][1] = !cnt[1], base[1][2] = !cnt[2];
    base[2][0] = 0, base[2][1] = !cnt[1], base[2][2] = !cnt[2];
    expo(to - fro), mult(ret, ans, tmp), copy(tmp, ans);
  }
  cout << (ans[1][0] + ans[1][1] + ans[1][2]) % MOD << '\n';
  return 0;
}