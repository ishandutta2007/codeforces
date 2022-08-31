#include <iostream>

using namespace std;

typedef long long ll;

ll ceil (ll p, ll q) {
  return (p + q - 1) / q;
}

ll seqsum (ll a, ll d, ll n) {
  ll pr = a + (a + (n - 1) * d);
  if (n % 2 == 1) {
    return ((n - 1) / 2) * pr + pr / 2;
  } else {
    return (n / 2) * pr;
  }
}

ll A, B;

ll seqsum (int l, int r) {
  return seqsum(A + (ll) (l - 1) * B, B, r - l + 1);
}

bool can (int l, int r, int t, int m) {
  return max(ceil(seqsum(l, r), m), A + (ll) (r - 1) * B) <= t;
}

int query (int l, int t, int m) {
  if (!can(l, l, t, m)) {
    return -1;
  }

  int ans = 0;
  for (int k = 1 << 30; k != 0; k /= 2) {
    if (can(l, l + ans + k, t, m)) {
      ans += k;
    }
  }
  return l + ans;
}

int main () {
  ios::sync_with_stdio(false);

  int qc;
  cin >> A >> B >> qc;

  for (int i = 0; i < qc; i++) {
    int l, t, m;
    cin >> l >> t >> m;

    cout << query(l, t, m) << '\n';
  }
}