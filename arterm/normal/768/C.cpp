#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 1055;
const int A = 10;

int n, k, x, a[M];
int b[M];

void read() {
  cin >> n >> k >> x;
  for (int i = 0; i < n; ++i) {
    int y;
    cin >> y;
    a[y]++;
  }
}

void step() {
  int cur = 0;
  fill(b, b + M, 0);
  for (int i = 0; i < (1 << A); ++i) {
    int t = a[i];
    int to = (t - cur + 1) >> 1;
    b[i ^ x] += to;
    b[i] += t - to;
    cur ^= t & 1;
  }
  copy(b, b + M, a);
}

void kill() {
  for (int i = 0; i < k; ++i)
    step();

  int mn = M, mx = 0;
  for (int i = 0; i < (1 << A); ++i)
    if (a[i]) {
      mn = min(i, mn);
      mx = max(i, mx);
    }

  cout << mx << " " << mn << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}