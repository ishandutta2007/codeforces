#include <iostream>

using namespace std;

const int MAX_N = 5e3 + 5;

typedef long long ll;

typedef pair<ll, ll> Point;
#define x first
#define y second

Point arr [MAX_N];
bool del [MAX_N];

ll sq (ll x) {
  return x * x;
}

ll dist (int u, int v) {
  Point p = arr[u], q = arr[v];

  return sq(p.x - q.x) + sq(p.y - q.y);
}

int farthest (int cur, int n) {
  pair<ll, int> ans = make_pair(0, cur);
  for (int i = 1; i <= n; i++) {
    if (!del[i]) {
      ans = max(ans, make_pair(dist(cur, i), i));
    }
  }
  return ans.second;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i].x >> arr[i].y;
  }

  int cur = 1;
  cout << 1 << " ";
  for (int i = 0; i < n - 1; i++) {
    del[cur] = 1;
    cur = farthest(cur, n);
    cout << cur << " ";
  }
  cout << '\n';
}