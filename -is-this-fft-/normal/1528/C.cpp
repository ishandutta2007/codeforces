#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 3e5 + 5;

vector<int> ch_a [MAX_N];
vector<int> ch_b [MAX_N];

int lfend [MAX_N];
int rgend [MAX_N];

set<pair<int, int>> cur_cover; // <lfend[u], u>

void unpaint (int u) {
  // cerr << " UNPAINT " << u << endl;
  cur_cover.erase(make_pair(lfend[u], u));
}

int cur_par (int u) {
  auto it = cur_cover.upper_bound(make_pair(lfend[u], -1));
  if (it == cur_cover.begin()) {
    return -1;
  }

  int p = prev(it)->second;
  if (lfend[p] <= lfend[u] && lfend[u] <= rgend[p]) {
    return p;
  }
  return -1;
}

int paint (int u) {
  int p = cur_par(u);
  if (p != -1) {
    unpaint(p);
  }
  cur_cover.insert(make_pair(lfend[u], u));
  // cerr << " PAINT " << u << " REMOVING " << p << endl;
  return p;
}

void build_flat (int u, int &cur) {
  cur++;
  lfend[u] = cur;
  for (int nxt : ch_b[u]) {
    build_flat(nxt, cur);
  }
  rgend[u] = cur;
}

void dfs (int u, int &ans) {
  int rp = paint(u);
  
  for (int nxt : ch_a[u]) {
    dfs(nxt, ans);
  }

  if (ch_a[u].empty()) {
    ans = max(ans, (int) cur_cover.size());
  }
  
  unpaint(u);
  if (rp != -1) paint(rp);
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    ch_a[i].clear();
    ch_b[i].clear();
  }
  cur_cover.clear();

  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;

    ch_a[p].push_back(i);
  }

  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;

    ch_b[p].push_back(i);
  }

  int cur = 0;
  build_flat(1, cur);

  int ans = 0;
  dfs(1, ans);

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}