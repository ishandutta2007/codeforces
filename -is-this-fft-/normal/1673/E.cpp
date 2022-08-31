#include <iostream>

using namespace std;

typedef long long ll;

// parity of - given n balls, how many ways to pick up at least m
int wpgem (int n, int m) {
  if (m > n) {
    return 0;
  }

  if (m == 0) {
    if (n == 0)
      return 1;
    else
      return 0;
  }

  return ((m - 1) & (n - 1)) == (m - 1);
}

int ways (int l, int r, int n, int k) {
  if (l == 0 && r == n - 1) {
    if (k == 0)
      return 1;
    return 0;
  }

  int len = r - l + 1;
  int rem = n - len;
  if (l == 0 || r == n - 1) {
    return wpgem(rem - 1, max(k - 1, 0));
  }

  return wpgem(rem - 2, max(k - 2, 0));
}

const int MAX_N = 1 << 20;

int B [MAX_N];
int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }

  for (int l = 0; l < n; l++) {
    ll bit = B[l];
    ans[bit] ^= ways(l, l, n, K);

    for (int r = l + 1; r < n; r++) {
      if (B[r] >= 20)
        break;

      bit <<= B[r];
      if (bit > MAX_N)
        break;

      ans[bit] ^= ways(l, r, n, K);
    }
  }

  bool lead = true;
  for (int i = MAX_N - 1; i >= 0; i--) {
    if (ans[i])
      lead = false;

    if (!lead) {
      cout << ans[i];
    }
  }

  if (lead)
    cout << 0;
  cout << '\n';
}