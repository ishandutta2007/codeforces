#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <cctype>
using namespace std;

map<string, int> mp;
int sz = 0;

int GetIndex(const string& str) {
  if (mp.find(str) == mp.end()) {
    mp[str] = sz++;
    return sz - 1;
  }
  return mp[str]; 
}

string ToLower(const string& s) {
  string t = s;
  for (auto it = t.begin(); it != t.end(); ++it) {
    *it = tolower(*it);
  }
  return t;
}

const int kN = 300;
vector<int> g[kN];

int dp[kN];

int DP(int u) {
  if (dp[u] == -1) {
    dp[u] = 0;
    for (int i = 0; i < g[u].size(); ++i) {
      dp[u] = max(dp[u], DP(g[u][i]));
    }
    ++dp[u];
  }
  return dp[u];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string src, reposted, dst;
    cin >> dst >> reposted >> src;
    src = ToLower(src);
    dst = ToLower(dst);
    g[GetIndex(src)].push_back(GetIndex(dst));
  }
  memset(dp, 255, sizeof(dp));
  int res = 0;
  for (int u = 0; u < sz; ++u) {
    res = max(res, DP(u));
  }
  cout << res;
  return 0;
}