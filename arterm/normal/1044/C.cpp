#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 300300;

int n;
int x[M], y[M];
vector<int> good;

int dist(int i, int j) {
  return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int triag(int i, int j, int k) {
  return dist(i, j) + dist(j, k) + dist(k, i);
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
}

void kill() {
  int x_min = *min_element(x, x + n);
  int y_min = *min_element(y, y + n);

  int x_max = *max_element(x, x + n);
  int y_max = *max_element(y, y + n);

  for (int i = 0; i < n; ++i)
    if (x[i] == x_min || x[i] == x_max || y[i] == y_min || y[i] == y_max) {
      good.push_back(i);
    }

  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int a : good)
      for (int b : good)
        ans = max(ans, triag(i, a, b));

  cout << ans << " ";
  ans = 2 * (x_max - x_min) + 2 * (y_max - y_min);
  for (int i = 4; i <= n; ++i)
    cout << ans << " ";
  cout << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}