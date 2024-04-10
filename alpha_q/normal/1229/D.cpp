#include <bits/stdc++.h>

using namespace std;

const int K = 125;
const int N = 200010;

vector <int> perm[K];
int n, k, comp[K][K], a[N], last[K];

int main() {
  cin >> n >> k;
  vector <int> id(k);
  for (int i = 0; i < k; ++i) id[i] = i;
  map <vector <int>, int> to;
  int ptr = 0;
  do {
    perm[ptr] = id, to[id] = ptr++;
  } while (next_permutation(id.begin(), id.end()));
  for (int i = 0; i < ptr; ++i) {
    for (int j = 0; j < ptr; ++j) {
      vector <int> res(k);
      for (int p = 0; p < k; ++p) res[p] = perm[i][perm[j][p]];
      comp[i][j] = to[res];
    }
  }
  for (int i = 1; i <= n; ++i) {
    vector <int> cur(k);
    for (int j = 0; j < k; ++j) scanf("%d", &cur[j]), --cur[j];
    a[i] = to[cur];
  }
  set <int> bars;
  bars.emplace(0);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (last[a[i]]) bars.erase(-last[a[i]]);
    last[a[i]] = i, bars.emplace(-last[a[i]]);
    vector <int> gens;
    bitset <K> reachable;
    reachable[0] = 1, gens.emplace_back(0);
    int at = i;
    for (int x : bars) {
      int cur = a[-x];
      ans += (long long) (at + x) * reachable.count(), at = -x;
      if (!reachable[cur]) {
        gens.emplace_back(cur);
        queue <int> q({0});
        reachable.reset(), reachable[0] = 1;
        while (!q.empty()) {
          int u = q.front(); q.pop();
          for (int y : gens) if (!reachable[comp[u][y]]) {
            reachable[comp[u][y]] = 1, q.emplace(comp[u][y]);
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}