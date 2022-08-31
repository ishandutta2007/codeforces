#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

int perm [MAX_N];
pair<int, int> swaps [MAX_N];

int cyc [MAX_N]; // name of the cycle
int cyc_sz [MAX_N];
int cyc_idx [MAX_N]; // idx within the cycle

void dfs (int u, int c, int idx) {
  cyc[u] = c;
  cyc_sz[c]++;
  cyc_idx[u] = idx;

  if (cyc[perm[u]] == 0) {
    dfs(perm[u], c, idx + 1);
  }
}

vector<int> swaps_of [MAX_N];
int cnt_action_ends [MAX_N];
vector<int> active_swaps;

void find_next (int u) {
  if (!swaps_of[u].empty()) {
    int nxt = swaps_of[u].back();
    cnt_action_ends[nxt]++;
    if (cnt_action_ends[nxt] == 2) {
      active_swaps.push_back(nxt);
    }
  }
}

class Comp {
  int u;

public:
  Comp (int _u = 0) : u(_u) {}

  bool operator() (int p, int q) {
    p = oth(p);
    q = oth(q);

    return dist(p) < dist(q);
  }

  int oth (int swap_id) {
    return swaps[swap_id].first ^ swaps[swap_id].second ^ u;
  }

  int dist (int v) {
    int csz = cyc_sz[cyc[u]];
    return (cyc_idx[v] - cyc_idx[u] + csz) % csz;
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> perm[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> swaps[i].first >> swaps[i].second;
    
    swaps_of[swaps[i].first].push_back(i);
    swaps_of[swaps[i].second].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    if (cyc[i] == 0) {
      dfs(i, i, 0);
    }
  }

  for (int i = 1; i <= n; i++) {
    auto cmp = Comp(i);
    sort(swaps_of[i].rbegin(), swaps_of[i].rend(), cmp);
  }
  
  for (int i = 1; i <= n; i++) {
    find_next(i);
  }
  
  for (int i = 0; i < m; i++) {
    int cur = active_swaps.back();
    active_swaps.pop_back();

    cout << 1 + cur << " ";

    auto pr = swaps[cur];
    
    swaps_of[pr.first].pop_back();
    swaps_of[pr.second].pop_back();

    find_next(pr.first);
    find_next(pr.second);
  }
  cout << endl;
}