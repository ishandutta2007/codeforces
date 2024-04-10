#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;

int n, q;
int x[2][M];
int cnt = 0;

void read() {
  cin >> n >> q;
}

bool inside(int j, int i) {
  return 0 <= j && j <= 1 && 0 <= i && i < n;
}

int calc(int j, int i) {
  //cerr << j << " _ " << i << "\n";
  int ans = 0;
  for (int dx = -1; dx <= +1; ++dx)
    for (int dy = -1; dy <= +1; ++dy)
      if (dx != 0 || dy != 0) {
        int tj = j + dx;
        int ti = i + dy;
        //cerr << tj << " - " << ti << "\n";
        if (inside(tj, ti)) {
          if (x[tj][ti] == 0 && x[j][i] == 0 && tj != j)
            ++ans;
        }
      }
  return ans;
}

void kill() {
  for (int j = 0; j < 2; ++j)
    for (int i = 0; i < n; ++i)
      x[j][i] = 1;

  while (q--) {
    int j, i;
    cin >> j >> i;
    --j, --i;

    cnt -= calc(j, i);
    x[j][i] ^= 1;
    cnt += calc(j, i);

    if (cnt == 0)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}