#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+2;
int lpf[N];
ll val[N];
ll val1[N];
ll val2[N];
int use[N];
int n;

void finish() {
  cout << accumulate(use+1, use+n+1, 0) << '\n';
  for (int i = 1; i <= n; i++) {
    if (use[i]) cout << i << ' ';
  }
  cout << '\n';
  exit(0);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  mt19937_64 rng((ll)chrono::steady_clock::now().time_since_epoch().count());

  for (int i = 1; i < N; i++) {
    lpf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (lpf[i] == i) {
      val[i] = rng();
      for (int j = 2*i; j < N; j += i) {
        lpf[j] = i;
      }
    }
    else {
      val[i] = val[lpf[i]]^val[i/lpf[i]];
    }
  }
  for (int i = 1; i < N; i++) {
    val1[i] = val1[i-1]^val[i];
    val2[i] = val2[i-1]^val1[i];
  }

  cin >> n;
  for (int i = 1; i <= n; i++) use[i] = 1;
  ll x = val2[n];
  if (!x) finish();
  for (int i = 1; i <= n; i++) {
    if (val1[i] == x) {
      use[i] = 0;
      finish();
    }
  }
  unordered_map<ll, int> m;
  for (int i = 1; i <= n; i++) {
    if (m.count(val1[i]^x)) {
      use[i] = 0;
      use[m[val1[i]^x]] = 0;
      finish();
    }
    m[val1[i]] = i;
  }

  assert(n % 4 == 3);
  use[n] = 0;
  use[n/2] = 0;
  use[2] = 0;
  finish();
}