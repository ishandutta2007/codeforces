#include <iostream>
#include <vector>

typedef long long llong;

const int MAX_CITY = 100005;
const int MAX_BIT = 20;

using namespace std;

int val [MAX_CITY];
vector<int> adj [MAX_CITY];

llong ans [MAX_BIT];
llong onec [MAX_CITY], zeroc [MAX_CITY];

void dfs (int vertex, int bit, int parent) {
  onec[vertex] = 0;
  zeroc[vertex] = 0;
  
  llong flip = val[vertex] & 1LL << bit;

  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (adj[vertex][i] != parent) {
      dfs(adj[vertex][i], bit, vertex);
      
      ans[bit] += onec[vertex] * zeroc[adj[vertex][i]];
      ans[bit] += zeroc[vertex] * onec[adj[vertex][i]];

      if (flip) {
        onec[vertex] += zeroc[adj[vertex][i]];
        zeroc[vertex] += onec[adj[vertex][i]];
      } else {
        onec[vertex] += onec[adj[vertex][i]];
        zeroc[vertex] += zeroc[adj[vertex][i]];
      }
    }
  }

  if (flip) {
    onec[vertex]++;
  } else {
    zeroc[vertex]++;
  }

  ans[bit] += onec[vertex];
}

int main () {
  int cityc;
  cin >> cityc;

  for (int i = 1; i <= cityc; i++) {
    cin >> val[i];
  }

  for (int i = 0; i < cityc - 1; i++) {
    int u, v;
    cin >> u >> v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  llong answer = 0;
  for (int i = 0; i < MAX_BIT; i++) {
    dfs(1, i, 0);

    answer += (1LL << i) * ans[i];
  }

  cout << answer << endl;
}