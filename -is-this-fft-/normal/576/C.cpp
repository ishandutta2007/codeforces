#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> point;
#define x first
#define y second

const int BLOCK = 1e3;
const int MAX_N = 1e6 + 5;

point arr [MAX_N];

bool bymo (point p, point q) {
  if (p.x / BLOCK != q.x / BLOCK) {
    return p.x < q.x;
  }
  if ((p.x / BLOCK) % 2) {
    return p.y < q.y;
  }
  return p.y > q.y;
}

bool ibymo (int u, int v) {
  return bymo(arr[u], arr[v]);
}

int perm [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i].x >> arr[i].y;
    perm[i - 1] = i;
  }

  sort(perm, perm + n, ibymo);

  for (int i = 0; i < n; i++) {
    cout << perm[i] << ' ';
  }
  cout << '\n';
}