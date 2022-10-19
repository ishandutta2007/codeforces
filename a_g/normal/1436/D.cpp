#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+2;
ll citizens[maxn];
int leaves[maxn];
int a[maxn];
vector<int> children[maxn];
ll ans = 0;
int n;

void dfs(int v) {
  citizens[v] = a[v];
  if (!children[v].size()) {
    leaves[v] = 1;
  }
  else {
    for (int u: children[v]) {
      dfs(u);
      citizens[v] += citizens[u];
      leaves[v] += leaves[u];
    }
  }
  ans = max(ans, (citizens[v]+leaves[v]-1)/leaves[v]);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    children[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dfs(1);
  cout << ans << endl;
}