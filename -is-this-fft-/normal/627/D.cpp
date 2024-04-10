#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

int vertexc;

vector<int> adj [MAX_N];
vector<int> adj_id [MAX_N];

int arr [MAX_N];

bool active [MAX_N];
int vis [MAX_N];

vector<int> fuckup [MAX_N];
int fuckroot [MAX_N];
vector<int> sub_clean [MAX_N];

void dfs_dn (int vertex, int parent) {
  vis[vertex] = 1;
  
  int par_id = -1;
  int all_ch_ok = 1;
  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    int nxt = adj[vertex][i];
    if (active[nxt]) {
      if (nxt != parent) {
        dfs_dn(nxt, vertex);
      } else {
        par_id = i;
      }
    } else {
      all_ch_ok = 0;
    }
  }

  if (par_id != -1) {
    sub_clean[vertex][par_id] = all_ch_ok;
    int sub_part = 0;
    int oth_part = 0;
    for (int i = 0; i < (int) adj[vertex].size(); i++) {
      int nxt = adj[vertex][i];
      int nxt_id = adj_id[vertex][i];
      if (active[nxt]) {
        if (nxt != parent) {
          sub_clean[vertex][par_id] &= sub_clean[nxt][nxt_id];
          if (sub_clean[nxt][nxt_id]) {
            sub_part += fuckup[nxt][nxt_id];
          } else {
            oth_part = max(oth_part, fuckup[nxt][nxt_id]);
          }
        }
      }
    }
    fuckup[vertex][par_id] = sub_part + oth_part + 1;
  }
}

void dfs_up (int vertex, int parent) {
  // calculate the fuckroot
  int cleanc = 0;
  int sub_part = 0;
  pair<int, int> best_oth = {0, 0};
  pair<int, int> sbest_oth = {0, 0};
  int all_ch_ok = 1;
  
  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    int nxt = adj[vertex][i];
    int nxt_id = adj_id[vertex][i];

    if (active[nxt]) {
      cleanc += sub_clean[nxt][nxt_id];
      if (sub_clean[nxt][nxt_id]) {
        sub_part += fuckup[nxt][nxt_id];
      } else {
        pair<int, int> cp = {fuckup[nxt][nxt_id], nxt};
        if (cp > best_oth) {
          sbest_oth = best_oth;
          best_oth = cp;
        } else if (cp > sbest_oth) {
          sbest_oth = cp;
        }
      }
    } else {
      all_ch_ok = 0;
    }
  }
  fuckroot[vertex] = 1 + sub_part + best_oth.first;

  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    int nxt = adj[vertex][i];
    int nxt_id = adj_id[vertex][i];

    if (active[nxt] && nxt != parent) {
      sub_clean[vertex][i] = all_ch_ok &&
        (cleanc - sub_clean[nxt][nxt_id] == (int) adj[vertex].size() - 1);
      if (sub_clean[nxt][nxt_id]) {
        fuckup[vertex][i] = fuckroot[vertex] - fuckup[nxt][nxt_id];
      } else if (nxt == best_oth.second) {
        fuckup[vertex][i] = fuckroot[vertex] - best_oth.first + sbest_oth.first;
      } else {
        fuckup[vertex][i] = fuckroot[vertex];
      }
    }
  }

  for (int nxt : adj[vertex]) {
    if (active[nxt] && nxt != parent) {
      dfs_up(nxt, vertex);
    }
  }
}

int solve_for (int target) {
  for (int i = 1; i <= vertexc; i++) {
    active[i] = 0;
    vis[i] = 0;
  }

  for (int i = 1; i <= vertexc; i++) {
    if (arr[i] >= target) {
      active[i] = 1;
    }
  }

  for (int i = 1; i <= vertexc; i++) {
    if (active[i] && !vis[i]) {
      dfs_dn(i, -1);
      dfs_up(i, -1);
    }
  }

  int ans = 0;
  for (int i = 1; i <= vertexc; i++) {
    if (active[i]) {
      ans = max(ans, fuckroot[i]);
    }
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int target;
  cin >> vertexc >> target;

  for (int i = 1; i <= vertexc; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj_id[u].push_back(adj[v].size());
    adj_id[v].push_back(adj[u].size());
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= vertexc; i++) {
    fuckup[i] = vector<int> (adj[i].size());
    sub_clean[i] = vector<int> (adj[i].size());
  }

  int ans = 0;
  for (int i = 1 << 20; i != 0; i /= 2) {
    if (solve_for(ans + i) >= target) {
      ans += i;
    }
  }

  cout << ans << endl;
}