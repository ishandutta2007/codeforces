#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int mul(int x, int y) {
  return (1ll * x * y) % mod;
}

const int M = 207;
const int K = 1010;

int d[M][K], h[M][K];
int n, k, a[M];

void ini() {
  d[0][0] = 1;
}

void upd(int i, int k, int w) {
  if (i < 0 || i >= M || k < 0 || k >= K)
    return;
  h[i][k] = add(h[i][k], w);
}

void add(int diff) {
  for (int i = 0; i < M; ++i)
    fill(h[i], h[i] + K, 0);

  for (int i = 0; i < M; ++i)
    for (int k = 0; k < K; ++k)
      if (d[i][k] != 0) {
        int to = mul(i, d[i][k]);
        //close
        if (i >= 1)
          upd(i - 1, k + (i - 1) * diff, to);
        //mid
        upd(i, k + i * diff, to);
        //open
        upd(i + 1, k + (i + 1) * diff, d[i][k]);
        //open and close
        upd(i, k + i * diff, d[i][k]);
      }

  for (int i = 0; i < M; ++i)
    copy(h[i], h[i] + K, d[i]);
}

void read() {
  cin >> n;
  cin >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  a[n] = 1e6;

  ini();
  for (int i = 0; i < n; ++i)
    add(a[i + 1] - a[i]);
  int ans = 0;
  for (int i = 0; i <= k; ++i)
    ans = add(ans, d[0][i]);
  cout << ans << endl;
}



int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
}