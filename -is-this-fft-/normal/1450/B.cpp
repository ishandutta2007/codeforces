#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> point;
#define x first
#define y second

int dist (point p, point q) {
  return abs(p.x - q.x) + abs(p.y - q.y);
}

const int MAX_N = 105;

point pos [MAX_N];

bool is_center (int idx, int n, int K) {
  for (int i = 0; i < n; i++) {
    if (dist(pos[idx], pos[i]) > K) return false;
  }
  return true;
}

void solve () {
  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n; i++) {
    cin >> pos[i].x >> pos[i].y;
  }

  for (int i = 0; i < n; i++) {
    if (is_center(i, n, K)) {
      cout << 1 << '\n';
      return;
    }
  }

  cout << -1 << '\n';
  return;
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}