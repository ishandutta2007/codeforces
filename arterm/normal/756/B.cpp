#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 100100;

int n;
int t[M];
int d[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> t[i];
}

void kill() {
  d[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int x = t[i - 1];
    d[i] = d[i - 1] + 20;

    {
      int pos = upper_bound(t, t + n, x - 90) - t;
      pos = max(pos, 0);
      d[i] = min(d[i], d[pos] + 50);
    }

    
    {
      int pos = upper_bound(t, t + n, x - 1440) - t;
      pos = max(pos, 0);
      d[i] = min(d[i], d[pos] + 120);
    }

    cout << d[i] - d[i - 1] << "\n";
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