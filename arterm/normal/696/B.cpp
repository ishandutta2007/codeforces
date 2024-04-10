#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 100100;

vector<int> g[M];
int n, sum[M];
ld ans[M];

void dfs1(int v) {
  sum[v] = 1;
  for (int to : g[v]) {
    dfs1(to);
    sum[v] += sum[to];
  }
}

void dfs(int v, int up, int d) {
  ans[v] = 0.5 * up + d;
  int cur = sum[v];
  for (int to : g[v]) {
    dfs(to, up + (cur - sum[to] - 1), d + 1);
  }
}

void read() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i);
  }
}


void kill() {
  dfs1(0);
  dfs(0, 0, 1);
  for (int i = 0; i < n; ++i)
    cout << ans[i] << " ";
  cout << endl;
}

int main() {
  cout.precision(3);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}