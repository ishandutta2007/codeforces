#include <bits/stdc++.h>
using namespace std;

const int N = 4005;
int bal[N];
vector<int> children[N];
int ans = 0;

void dfs(int v) {
  for (int u: children[v]) {
    dfs(u);
    bal[v] += bal[u];
  }
  if (!bal[v]) ans++;
}


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ans = 0;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      children[p].push_back(i);
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
      if (s[i-1] == 'W') bal[i] = 1;
      else bal[i] = -1;
    }
    dfs(1);
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
      children[i].clear();
    }
  }
}