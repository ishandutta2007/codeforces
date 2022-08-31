#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 200005;

vector<int> adj [MAX_N];
ll weight [MAX_N];
int comp [MAX_N];
vector<int> cur_comp;
ll ans;

void mark_comp (int vertex, int comp_id) {
  cur_comp.push_back(vertex);
  comp[vertex] = comp_id;
  for (int nxt : adj[vertex]) {
    if (comp[nxt] == 0) {
      mark_comp(nxt, comp_id);
    }
  }
}

vector<int> alt_adj [2 * MAX_N];
ll alt_weight [2 * MAX_N];
int non_tail_nbs [MAX_N];
bool tail [MAX_N];
int onpath [MAX_N];
ll dp [2 * MAX_N];

ll calc_dp (int vertex, int parent) {
  dp[vertex] = alt_weight[vertex];
  for (int nxt : alt_adj[vertex]) {
    if (nxt != parent) {
      calc_dp(nxt, vertex);
      dp[vertex] = max(dp[vertex], alt_weight[vertex] + dp[nxt]);
    }
  }
  return dp[vertex];
}

ll sumw (int vertex, int parent, int spec) {
  ll cur = -1;
  for (int nxt : alt_adj[vertex]) {
    if (nxt != parent) {
      cur = max(cur, sumw(nxt, vertex, spec));
    }
  }

  if (cur >= 0 || vertex == spec) {
    cur = max(0LL, cur);
    return cur + weight[vertex];
  } else {
    return -1;
  }
}

bool rem_weights (int vertex, int parent, int spec) {
  bool rem = false;
  for (int nxt : alt_adj[vertex]) {
    if (nxt != parent) {
      rem |= rem_weights(nxt, vertex, spec);
    }
  }

  if (vertex == spec) {
    rem = true;
  }

  if (rem) {
    ans += alt_weight[vertex];
    alt_weight[vertex] = 0;
  }

  return rem;
}

void proc_cur_comp (int start) {  
  int edgec = 0;
  for (int v : cur_comp) {
    edgec += adj[v].size();
  }
  edgec /= 2;

  int root;
  if ((int) cur_comp.size() <= 2) {
    ll cur_ans = 0;
    for (int u : cur_comp) {
      cur_ans += weight[u];
    }
    ans = max(ans, cur_ans);
  } else if (edgec < (int) cur_comp.size()) {
    // we have a tree!
    for (int u : cur_comp) {
      alt_weight[u] = weight[u];
      alt_adj[u] = adj[u];
    }
    ans = max(ans, calc_dp(start, start));
  } else {
    vector<int> Q;
    for (int u : cur_comp) {
      if ((int) adj[u].size() == 1) {
        Q.push_back(u);
      }
      non_tail_nbs[u] = (int) adj[u].size();
    }

    for (int i = 0; i < (int) Q.size(); i++) {
      int qtop = Q[i];

      tail[qtop] = 1;
      
      for (int nxt : adj[qtop]) {
        if (!tail[nxt]) {
          non_tail_nbs[nxt]--;

          if (non_tail_nbs[nxt] == 1) {
            Q.push_back(nxt);
          }
        }
      }
    }

    root = MAX_N + cur_comp[0];
    for (int u : cur_comp) {
      if (tail[u]) {
        if (!onpath[u]) {
          alt_weight[u] = weight[u];
        }

        bool root_child = false;
        for (int nxt : adj[u]) {
          if (tail[nxt]) {
            alt_adj[u].push_back(nxt);
          } else {
            root_child = 1;
          }
        }

        if (root_child) {
          alt_adj[u].push_back(root);
          alt_adj[root].push_back(u);
        }
      } else {
        alt_weight[root] += weight[u];
      }
    }
    
    if (tail[start]) {
      rem_weights(root, root, start);
      ans += calc_dp(root, root);
    } else {
      ans = calc_dp(root, root);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 1; i <= vertexc; i++) {
    cin >> weight[i];
  }
  
  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int start;
  cin >> start;

  mark_comp(start, start);
  proc_cur_comp(start);

  cout << ans << endl;
}