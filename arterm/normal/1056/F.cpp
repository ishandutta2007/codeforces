#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef double ld;
typedef long long ll;

const int M = 107;
const int S = M * 10;
const ld inf = 1e18;

ld d[M][S];

int n;
ld t, c;
pair<int, int> task[M];
ld by = 1 / .9;

ld uin(ld &x, ld y) {
  return x = min(x, y);
}

void read() {
  cin >> n;
  cin >> c >> t;
  for (int i = 0; i < n; ++i) {
    int a, p;
    cin >> a >> p;
    task[i] = make_pair(a, p);
  }
  sort(task, task + n);
}


bool check(ld A, ld B, ld C, ld T) {
  ld a = C;
  ld b = 1 + A * C - T * C;
  ld c = (A + B - T);

  ld d = b * b - 4 * a * c;

  if (d < 0)
    return false;

  return (b <= 0 || c <= 0);
}

void kill() {
  for (int i = 0; i <= n; ++i)
    for (int k = 0; k < S; ++k)
      d[i][k] = inf;

  d[0][0] = 0;

  int sum = 0;
  for (int j = 0; j < n; ++j) {
    int a = task[j].first;
    int p = task[j].second;
    for (int i = j; i >= 0; --i)
      for (int cur = 0; cur <= sum; ++cur)
        if (d[i][cur] < inf / 2) {
          uin(d[i + 1][cur + p], d[i][cur] * by + a);
        }
    sum += p;
  }

  int ans = 0;
  for (int i = 0; i <= n; ++i)
    for (int k = 0; k <= sum; ++k)
      if (d[i][k] < inf / 2) {
        //if (k == 9) {
          //cerr << d[i][k] << "!\n";
          //cerr << i << "!!\n";
        //}
        if (check(10 * i, d[i][k] * by, c, t))
          ans = max(ans, k);
      }

  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int tc;
  cin >> tc;
  while (tc--) {
    read();
    kill();
  }
}