#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100005;

vector<int> adj [MAX_N];
int lvl [MAX_N];
int dp [MAX_N];
bool bridge;
vector<pair<int, int>> ans;

void dfs (int vertex, int parent) {
  lvl[vertex] = lvl[parent] + 1;

  for (int nxt : adj[vertex]) {
    if (lvl[nxt] != 0) {
      if (nxt != parent) {
        if (lvl[nxt] > lvl[vertex]) {
          dp[vertex]--;
          ans.push_back(make_pair(nxt, vertex));
        } else if (lvl[nxt] < lvl[vertex]) {
          dp[vertex]++;
        }
      }
    } else {
      dfs(nxt, vertex);
      ans.push_back(make_pair(vertex, nxt));
      dp[vertex] += dp[nxt];
    }
  }

  if (dp[vertex] == 0 && vertex != parent) {
    bridge = true;
  }
}

int main () {
  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 1);

  if (bridge) {
    cout << 0 << endl;
  } else {
    for (pair<int, int> pr : ans) {
      cout << pr.first << " " << pr.second << '\n';
    }
  }
}