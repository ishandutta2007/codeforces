#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_LG = 18;

vector<int> adj [MAX_N];
bool is_marked [MAX_N];

int lvl [MAX_N];
int jmp [MAX_N][MAX_LG];

void build (int u, int p) {
  lvl[u] = lvl[p] + 1;
  jmp[u][0] = p;
  for (int i = 1; i < MAX_LG; i++) {
    jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      build(nxt, u);
    }
  }
}

int go_up (int u, int d) {
  for (int k = 0; k < MAX_LG; k++) {
    if (d & 1 << k) {
      u = jmp[u][k];
    }
  }
  return u;
}

int lca (int u, int v) {
  if (lvl[u] < lvl[v]) {
    swap(u, v);
  }

  u = go_up(u, lvl[u] - lvl[v]);
  if (u == v) {
    return u;
  }

  for (int i = MAX_LG - 1; i >= 0; i--) {
    if (jmp[u][i] != jmp[v][i]) {
      u = jmp[u][i];
      v = jmp[v][i];
    }
  }

  return jmp[u][0];
}

int move_to_at_most (int u, int v, int D) {
  int lc = lca(u, v);
  int dist = lvl[u] + lvl[v] - 2 * lvl[lc];

  if (dist <= D) {
    return u;
  }

  int target = dist - D;
  if (target <= lvl[u] - lvl[lc]) {
    return go_up(u, target);
  } else {
    return go_up(v, D);
  }
}

const int INF = 1e9 + 5;
class TwoBest {
  pair<int, int> best; // <value, index>
  pair<int, int> sbest;
  
public:
  TwoBest () {
    best = make_pair(-INF, 0);
    sbest = make_pair(-INF, 0);
  }
  
  void add (int idx, int val) {
    auto pr = make_pair(val, idx);
    if (pr > best) {
      sbest = best;
      best = pr;
    } else if (pr > sbest) {
      sbest = pr;
    }
  }

  int max_except (int idx) {
    if (best.second == idx) return sbest.first;
    return best.first;
  }
};

int far [MAX_N];
void build_rooted (int u, int p) {
  far[u] = -INF;
  if (is_marked[u]) {
    far[u] = 0;
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      build_rooted(nxt, u);
      far[u] = max(far[u], 1 + far[nxt]);
    }
  }
}

void solve (int u, int p, int dist, int D, int &ans) {
  if (dist <= D) {
    ans++;
  } else {
    return;
  }

  if (is_marked[u]) {
    dist = max(dist, 0);
  }

  TwoBest tb;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      tb.add(nxt, far[nxt] + 1);
    }
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      solve(nxt, u, 1 + max(dist, tb.max_except(nxt)), D, ans);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, m, D;
  cin >> n >> m >> D;

  vector<int> marked (m);
  for (int i = 0; i < m; i++) {
    cin >> marked[i];
    is_marked[marked[i]] = 1;
  }
  
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  build(1, 0);

  int cur = 1;
  for (int v : marked) {
    cur = move_to_at_most(cur, v, D);
  }

  build_rooted(cur, 0);
  if (far[cur] > D) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  solve(cur, 0, -INF, D, ans);
  cout << ans << endl;
}