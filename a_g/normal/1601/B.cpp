#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<pair<int, int>> c(n);
  vector<vector<int>> nbrs(n+1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[i] = {i+1-a[i], i+1};
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    nbrs[i+1+b[i]].push_back(i+1);
  }
  sort(c.begin(), c.end());
  vector<int> prev(n+1);
  vector<int> s(n+1, 0);
  int index = 0;
  set<int> visited;
  queue<int> q;
  
  q.push(0);
  visited.insert(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    while (index < n && c[index].first <= v) {
      for (int u: nbrs[c[index].second]) {
        if (!visited.count(u)) {
          visited.insert(u);
          q.push(u);
          prev[u] = v;
        }
      }
      index++;
    }
  }
  if (prev[n] == 0 && a[n-1] < n) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans;
  int v = n;
  while (v != 0) {
    ans.push_back(prev[v]);
    v = prev[v];
  }
  cout << ans.size() << endl;
  for (int v: ans) cout << v << " ";
  cout << endl;
}