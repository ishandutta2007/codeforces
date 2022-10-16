#include <bits/stdc++.h>
#include <ios>

using namespace std;

using lint = long long int;
const int NMAX = 100000 + 5;

int N;
int l[NMAX];
int r[NMAX];

vector<int> graph[NMAX];

lint dp[NMAX][2];

void dfs(int node, int father) {
  dp[node][0] = dp[node][1] = 0;
  for (auto it : graph[node]) {
    if (it != father) {
      dfs(it, node);
      dp[node][0] += max(abs(l[node] - l[it]) + dp[it][0],
                         abs(l[node] - r[it]) + dp[it][1]);
      dp[node][1] += max(abs(r[node] - l[it]) + dp[it][0],
                         abs(r[node] - r[it]) + dp[it][1]);
    }
  }
}

lint solve() {
  dfs(1, 0);
  return max(dp[1][0], dp[1][1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 0;
  cin >> t;
  while (t--) {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
      graph[i].clear();
      cin >> l[i] >> r[i];
    }
    for (int i = 1; i < N; ++i) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    cout << solve() << endl;
  }
}