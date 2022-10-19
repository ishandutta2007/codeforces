#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;

int n, m, k;
vector<pair<int, pair<int, int>>> e;
int p[M], r[M], cnt[M];

void ini() {
  iota(p, p + M, 0);
  fill(r, r + M, 0);
}

int get(int x) {
  return p[x] = (p[x] == x) ? x : get(p[x]);
}

int uni(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) return x;
  if (r[x] < r[y]) {
    swap(x, y);
  }
  r[x]++;
  cnt[x] += cnt[y];
  p[y] = x;
  return x;
}
  

void read() {
  cin >> n >> m >> k;
  fill(cnt, cnt + n, 0);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    --x;
    cnt[x] = 1;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    e.emplace_back(w, make_pair(u, v));
  }
}

void kill() {
  sort(all(e));
  ini();
  int ans = -1;
  for (auto cur : e) {
    int u = cur.second.first;
    int v = cur.second.second;
    int x = uni(u, v);
    if (cnt[x] == k) {
      ans = cur.first;
      break;
    }
  }
  assert(ans != -1);
  for (int i = 0; i < k; ++i)
    cout << ans << " ";
  cout << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}