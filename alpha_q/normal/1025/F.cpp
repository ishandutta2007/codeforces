#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> point;

#define x first
#define y second

const int N = 2010;

point p[N], vec[N * N];
int n, m, id[N], pos[N]; 

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &p[i].x, &p[i].y);
  }
  sort(p, p + n);
  for (int i = 0; i < n; ++i) {
    id[i] = pos[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      vec[m++] = point(i, j);
      point cur = point(p[i].y - p[j].y, p[j].x - p[i].x);
      if (cur.y < 0 or (cur.y == 0 and cur.x > 0)) {
        swap(vec[m - 1].x, vec[m - 1].y);
      }
    }
  }
  sort(vec, vec + m, [] (point a, point b) {
    point c(p[a.x].y - p[a.y].y, p[a.y].x - p[a.x].x), d(p[b.x].y - p[b.y].y, p[b.y].x - p[b.x].x);
    return c.x * d.y > c.y * d.x;
  });
  ll ans = 0;
  for (int it = 0; it < m; ++it) {
    int i = vec[it].x, j = vec[it].y;
    assert(pos[j] - pos[i] == 1);
    ll a = pos[i], b = n - 2 - pos[i];
    ans += (ll) a * (a - 1) * b * (b - 1) / 4;
    swap(pos[i], pos[j]), swap(id[pos[i]], id[pos[j]]);
  }
  cout << ans << '\n';
  return 0;
}