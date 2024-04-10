#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N];
vector<int> G[N];
int dp[N], indeg[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  long long k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(a+1, a+n+1);
  sort(b.begin(), b.end());
  if (k == 1) {
    cout << b[0] << '\n';
    return 0;
  }
  vector<pair<int, int>> edges(m);
  for (auto& p: edges) {
    cin >> p.first >> p.second;
  }
  auto check = [&] (int z) {
    int thresh = b[z];
    fill(dp+1, dp+n+1, 0);
    fill(indeg+1, indeg+n+1, 0);
    fill(G+1, G+n+1, vector<int>());
    int validvertices = 0;
    vector<int> que;
    for (int i = 1; i <= n; i++) {
      if (a[i] <= thresh) {
        validvertices++;
        dp[i] = 1;
      }
    }

    for (pair<int, int>& p: edges) {
      if (a[p.first] <= thresh && a[p.second] <= thresh) {
        G[p.first].push_back(p.second);
        indeg[p.second]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] <= thresh && indeg[i] == 0) {
        que.push_back(i);
      }
    }
    for (int i = 0; i < (int)que.size(); i++) {
      for (int j: G[que[i]]) {
        indeg[j]--;
        dp[j] = max(dp[j], dp[que[i]]+1);
        if (dp[j] >= k) return true;
        if (indeg[j] == 0) que.push_back(j);
      }
    }
    if (que.size() < validvertices) return true;
    return false;
  };

  if (!check(n-1)) {
    cout << "-1\n";
    return 0;
  }
  int high = n-1;
  int low = -1;
  while (high-low > 1) {
    int mid = (low+high)/2;
    if (check(mid)) high = mid;
    else low = mid;
  }
  cout << b[high] << '\n';
}