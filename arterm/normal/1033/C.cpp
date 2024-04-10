#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;

vector<int> g[M];
int n, a[M];
bool used[M], win[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}

bool dfs(int v) {
  if (used[v]) return win[v];
  bool found = false;
  used[v] = true;

  for (int to : g[v])
    if (!dfs(to))
      found = true;

  return win[v] = found;
}

void kill() {
  for (int i = 0; i < n; ++i) {
    for (int j = (i % a[i]); j < n; j += a[i])
      if (j != i && a[j] > a[i])
        g[i].push_back(j);
  }

  for (int i = 0; i < n; ++i)
    cout << (dfs(i) ? "A" : "B");
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