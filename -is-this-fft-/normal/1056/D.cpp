#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100005;

vector<int> adj [maxn];
int subs [maxn];

void dfs (int vertex) {
  if (adj[vertex].size() == 0) {
    subs[vertex] = 1;
  } else {
    for (int nxt : adj[vertex]) {
      dfs(nxt);
      subs[vertex] += subs[nxt];
    }
  }
}

int main () {
  int vertexc;
  cin >> vertexc;

  for (int i = 2; i <= vertexc; i++) {
    int par;
    cin >> par;

    adj[par].push_back(i);
  }

  dfs(1);

  vector<int> ans;
  for (int i = 1; i <= vertexc; i++) {
    ans.push_back(subs[i]);
  }
  sort(ans.begin(), ans.end());
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}