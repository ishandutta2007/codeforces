#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_M = 3e5 + 5;

vector<pair<int, int>> adj [MAX_N]; 

void add_edge (int u, int v, int idx) {
  adj[u].push_back(make_pair(v, idx));
  adj[v].push_back(make_pair(u, idx));
}

int seen [MAX_M];
void euler (int start, vector<int> &ans) {
  vector<int> v_stk;

  v_stk.push_back(start);
  do {
    int cur = v_stk.back();
    int flag = 0;
    while (!adj[cur].empty()) {
      if (seen[adj[cur].back().second]) {
        adj[cur].pop_back();
      } else {
        seen[adj[cur].back().second] = 1;
        v_stk.push_back(adj[cur].back().first);
        adj[cur].pop_back();
        flag = 1;
        break;
      }
    }

    if (!flag) {
      ans.push_back(v_stk.back());
      v_stk.pop_back();
    }
  } while (!v_stk.empty());
  v_stk.push_back(start);
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    add_edge(u, v, i);
  }

  vector<int> odds;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() % 2 == 1) {
      odds.push_back(i);
    }
  }

  for (int i = 0; i < (int) odds.size(); i += 2) {
    add_edge(odds[i], odds[i + 1], m + i / 2);
  }

  int edgec = m + (int) odds.size() / 2;
  if (edgec % 2 == 1) {
    add_edge(1, 1, edgec);
    edgec++;
  }

  vector<int> ans;
  euler(1, ans);

  vector<pair<int, int>> anse;
  for (int i = 0; i < (int) ans.size() - 1; i++) {
    anse.push_back(make_pair(ans[i], ans[i + 1]));
  }
  
  cout << (int) anse.size() << '\n';
  for (int i = 0; i < (int) anse.size(); i++) {
    if (i % 2 == 1) {
      swap(anse[i].first, anse[i].second);
    }
    cout << anse[i].first << " " << anse[i].second << '\n';
  }
}