#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 1010;

int x[M], y[M];

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  int cnt[2] = {0, 0};
  while (true) {
    cnt[0] = 0;
    cnt[1] = 0;

    for (int i = 0; i < n; ++i)
      cnt[abs(x[i] + y[i]) % 2]++;

    if (cnt[0] != 0 && cnt[1] != 0)
      break;

    if (cnt[0] == 0) {
      for (int i = 0; i < n; ++i)
        x[i] -= 1;
    }

    for (int i = 0; i < n; ++i) {
      int a = (x[i] - y[i]) / 2;
      int b = (x[i] + y[i]) / 2;
      x[i] = a;
      y[i] = b;
    }
  }

  cout << cnt[0] << "\n";
  for (int i = 0; i < n; ++i)
    if (abs(x[i] + y[i]) % 2 == 0)
      cout << i + 1 << " ";
  cout << "\n";
}