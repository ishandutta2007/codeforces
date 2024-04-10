#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

const int MAX_N = 2e5 + 5;
const int MAX_E = 2e5 + 5;

vector<int> occs [MAX_E][2];
int sign [MAX_E];

void direct_edge (int idx, int u, int v) {
  // the variable shall be true at v
  if (u == occs[idx][0][0] && v == occs[idx][1][0]) {
    sign[idx] = 0;
  } else {
    sign[idx] = 1;
  }
}

int fpass [MAX_N];
vector<pair<int, int>> adj [MAX_N];
int vis [MAX_N];

void prop_pass (int u) {
  fpass[u] = 1;
  vis[u] = 1;
  for (auto pr : adj[u]) {
    int nxt = pr.first;
    if (sign[pr.second] == -1) {
      direct_edge(pr.second, u, nxt);
    }
    if (!vis[nxt]) {
      prop_pass(nxt);
    }
  }
}

bool find_cycle (int u, int p, deque<pair<int, int>> &cycle) {
  if (p == 0) {
    cycle.push_back(make_pair(u, 0));
  }
  vis[u] = 1;
  
  for (auto pr : adj[u]) {
    int nxt = pr.first;
    if (pr.second != p) {
      if (!vis[nxt]) {
        cycle.push_back(pr);
        if (find_cycle(nxt, pr.second, cycle)) return true;
        cycle.pop_back();
      } else {
        // we have seen the next!
        while (cycle[0].first != nxt) {
          cycle.pop_front();
        }
        cycle[0].second = pr.second;
        return true;
      }
    }
  }
  return false;
}

int vis2 [MAX_N];
void prop_tree (int u, int p1, int p2) {
  vis2[u] = 1;
  for (auto pr : adj[u]) {
    int nxt = pr.first;
    if (nxt != p1 && nxt != p2 && !vis2[nxt]) {
      direct_edge(pr.second, u, nxt);
      prop_tree(nxt, u, p2);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    sign[i] = -1;
  }

  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;

    for (int j = 0; j < k; j++) {
      int e;
      cin >> e;

      int neg = 0;
      if (e < 0) {
        e = -e;
        neg = 1;
      }

      occs[e][neg].push_back(i);
    }
  }

  for (int i = 1; i <= m; i++) {
    if (occs[i][0].empty() && occs[i][1].empty()) {
      sign[i] = 0;
    } else if (occs[i][0].empty() || occs[i][1].empty()) {
      for (int k = 0; k < 2; k++) {
        if (occs[i][k].empty()) {
          sign[i] = k;
          for (int v : occs[i][!k]) {
            fpass[v] = 1;
          }
        }
      }
    } else {
      int u = occs[i][0][0];
      int v = occs[i][1][0];
      adj[u].push_back(make_pair(v, i));
      adj[v].push_back(make_pair(u, i));
    }
  }

  for (int i = 1; i <= m; i++) {
    if (fpass[i] && !vis[i]) {
      prop_pass(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i] && !vis2[i]) {
      deque<pair<int, int>> cycle; // <vertex, edge from prev>
      if (!find_cycle(i, 0, cycle)) {
        failure();
      }
      for (int j = 0; j < (int) cycle.size() - 1; j++) {
        direct_edge(cycle[j + 1].second, cycle[j].first, cycle[j + 1].first);
      }
      direct_edge(cycle[0].second, cycle.back().first, cycle[0].first);

      if (cycle.size() == 2) {
        prop_tree(cycle[0].first, cycle[1].first, cycle[1].first);
        prop_tree(cycle[1].first, cycle[0].first, cycle[0].first);
      } else {
        prop_tree(cycle[0].first, cycle.back().first, cycle[1].first);
        for (int j = 1; j < (int) cycle.size() - 1; j++) {
          prop_tree(cycle[j].first, cycle[j - 1].first, cycle[j + 1].first);
        }
        prop_tree(cycle.back().first, cycle[(int) cycle.size() - 2].first, cycle[0].first);
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 1; i <= m; i++) {
    if (sign[i] == -1) sign[i] = 0;
    cout << sign[i];
  }
  cout << endl;
}