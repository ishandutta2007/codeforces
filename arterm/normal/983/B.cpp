#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 5005;
const int A = 13;

int n, a[M], b[M];
int d[M][M];

int bit(int mask, int i) {
  return (mask >> i) & 1;
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  //n = 5000;
  //for (int i = 0; i < n; ++i)
    //a[i] = rand();
}

void kill() {
  for (int i = 0; i < n; ++i) {
    int m = n - i;
    for (int j = 0; j < m; ++j)
      b[j] = a[i + j];

    for (int k = 0; k < A; ++k)
      for (int j = 0; j < m; ++j)
        if (bit(j, k))
          b[j] ^= b[j ^ (1 << k)];

    for (int j = 0; j < m; ++j)
      d[i][i + j + 1] = b[j];
  }

  for (int len = 2; len <= n; ++len)
    for (int i = 0; i + len <= n; ++i) {
      int j = i + len;
      d[i][j] = max({d[i][j], d[i + 1][j], d[i][j - 1]});
    }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    cout << d[l][r] << "\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}