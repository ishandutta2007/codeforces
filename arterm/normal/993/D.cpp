#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef ll ld;

const int M = 55;
const ld inf = 1e18;
const ld R = 10000;

int n;
ll a[M], b[M];
ld w[M];
ld d[M][M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] *= R;
  }
  for (int i = 0; i < n; ++i)
    cin >> b[i];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j + 1 < n; ++j)
      if (a[j] < a[j + 1] 
          || (a[j] == a[j + 1] && b[j] < b[j + 1])) {
        swap(a[j], a[j + 1]);
        swap(b[j], b[j + 1]);
      }
  for (int i = 0; i < n; ++i) {
    cerr << a[i] << endl;
    if (a[i] < a[i + 1])
      assert(!"akdjfldsakfldsakjfa");
  }
  //assert(is_sorted(a, a + n, greater<int>()));
}

void uin(ld &x, ld y) {
  x = min(x, y);
}

bool check(ld x) {
  for (int i = 0; i < n; ++i)
    w[i] = a[i] - b[i] * x;


  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      d[i][j] = inf;

  d[0][0] = 0;

  for (int i = 0; i < n; ) {
    int j = i;

    while (j < n && a[i] == a[j]) {
      ++j;
    }

    int m = j - i;

    for (int p = 0; p <= i; ++p) {
      if (d[i][p] >= inf / 2)
        continue;
      ld sum = 0;
      for (int k = 0; k <= m; ++k) {
        int diff = (m - k); // match
        if (diff <= p) {
          uin(d[j][p - diff + k], d[i][p] + sum);
        }
        sum += w[i + k];
      }
    }

    i = j;
  }

  for (int j = 0; j <= n; ++j)
    if (d[n][j] <= 0) {
      return true;
    }
  return false;
}

void kill() {
  ld l = 0, r = 1e9 * R;
  while (l < r) {
    ld m = (l + r) / 2;
    if (check(m))
      r = m;
    else
      l = m + 1;
  }

  cout << (l + 9) / 10 << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}