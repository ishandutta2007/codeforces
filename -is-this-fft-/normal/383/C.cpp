#include <iostream>
#include <vector>

const int MAX_LEN = 200005;

using namespace std;

vector<int> adj [MAX_LEN];
int dfs_l [MAX_LEN], dfs_r [MAX_LEN], parity [MAX_LEN], cur_len;

void dfs (int vertex, int parent) {
  cur_len++;
  dfs_l[vertex] = cur_len;

  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (adj[vertex][i] != parent) {
      parity[adj[vertex][i]] = !parity[vertex];
      dfs(adj[vertex][i], vertex);
    }
  }

  dfs_r[vertex] = cur_len + 1;
}

int fenwick [MAX_LEN];

void add (int index, int val) {
  for (int i = index; i < MAX_LEN; i += i & -i) {
    fenwick[i] += val;
  }
}

int get (int index) {
  int ans = 0;
  for (int i = index; i > 0; i -= i & -i) {
    ans += fenwick[i];
  }
  return ans;
}

int init [MAX_LEN];

int main () {
  ios::sync_with_stdio(false);

  int vertexc, queryc;
  cin >> vertexc >> queryc;
  
  for (int i = 0; i < vertexc; i++) {
    cin >> init[i];
  }

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, 0);

  for (int i = 0; i < queryc; i++) {
    int query;
    cin >> query;

    if (query == 1) {
      int vertex, val;
      cin >> vertex >> val;
      vertex--;
      
      if (parity[vertex]) {
        add(dfs_l[vertex], -val);
        add(dfs_r[vertex], val);
      } else {
        add(dfs_l[vertex], val);
        add(dfs_r[vertex], -val);
      }
    } else {
      int vertex;
      cin >> vertex;
      vertex--;

      if (parity[vertex]) {
        cout << init[vertex] - get(dfs_l[vertex]) << '\n';
      } else {
        cout << init[vertex] + get(dfs_l[vertex]) << '\n';
      }
    }
  }
}