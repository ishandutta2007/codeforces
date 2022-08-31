#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAX_N = 1e5 + 5;

typedef long long ll;
typedef double ld;

int root [MAX_N];
int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);
  root[u] = v;
}

vector<int> adj [MAX_N];
vector<int> comp_of [MAX_N];

int smallest [MAX_N];
vector<int> farth_in [MAX_N];
vector<int> pref_cnt [MAX_N];
vector<ll> pref_sum [MAX_N];

int farthest [MAX_N];

pair<int, int> naive_farthest (int u, int par) {
  pair<int, int> ans = {0, u};
  for (int nxt : adj[u]) {
    if (nxt != par) {
      pair<int, int> pr = naive_farthest(nxt, u);
      pr.first++;
      ans = max(pr, ans);
    }
  }
  return ans;
}

void populate_farthest (int u, int par, int cur) {
  farthest[u] = max(farthest[u], cur);
  for (int nxt : adj[u]) {
    if (nxt != par) {
      populate_farthest(nxt, u, cur + 1);
    }
  }
}

void process_component (int u) {
  u = find(u);

  int far1 = naive_farthest(u, u).second;
  int far2 = naive_farthest(far1, far1).second;

  populate_farthest(far1, far1, 0);
  populate_farthest(far2, far2, 0);

  vector<int> cur_dists;
  for (int v : comp_of[u]) {
    cur_dists.push_back(farthest[v]);
  }

  sort(cur_dists.begin(), cur_dists.end());

  smallest[u] = cur_dists.front();
  for (int i = 0; i < (int) cur_dists.size(); i++) {
    if (i == 0 || cur_dists[i] != cur_dists[i - 1]) {
      farth_in[u].push_back(0);
    }
    farth_in[u].back()++;
  }

  pref_cnt[u] = vector<int> ((int) farth_in[u].size(), 0);
  pref_cnt[u][0] = farth_in[u][0];
  for (int i = 1; i < (int) pref_cnt[u].size(); i++) {
    pref_cnt[u][i] = pref_cnt[u][i - 1] + farth_in[u][i];
  }

  pref_sum[u] = vector<ll> ((int) farth_in[u].size(), 0);
  pref_sum[u][0] = (ll) smallest[u] * farth_in[u][0];
  for (int i = 1; i < (int) pref_sum[u].size(); i++) {
    pref_sum[u][i] = pref_sum[u][i - 1] + (ll) (smallest[u] + i) * farth_in[u][i];
  }
}

ld solve (int u, int v) {
  u = find(u);
  v = find(v);

  if (smallest[u] + (int) farth_in[u].size() > smallest[v] + (int) farth_in[v].size()) {
    swap(u, v);
  }

  int diam = smallest[v] + (int) farth_in[v].size() - 1;
  ll ans = pref_sum[u].back() * (ll) pref_cnt[v].back()
    + pref_sum[v].back() * (ll) pref_cnt[u].back()
    + (ll) pref_cnt[u].back() * (ll) pref_cnt[v].back();
  for (int k = 0; k + smallest[u] + smallest[v] + 1 < diam && k < (int) farth_in[u].size(); k++) {
    int l = diam - k - smallest[u] - smallest[v] - 2;
    ans -= (ll) farth_in[u][k] * (ll) pref_cnt[v][l] * (ll) (smallest[u] + k);
    ans -= (ll) pref_sum[v][l] * (ll) farth_in[u][k];
    ans -= (ll) pref_cnt[v][l] * (ll) farth_in[u][k];
    ans += (ll) pref_cnt[v][l] * (ll) farth_in[u][k] * diam;
  }

  return (ld) ans / ((ld) pref_cnt[u].back() * (ld) pref_cnt[v].back()); 
}

int main () {
  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
  }
  
  ios::sync_with_stdio(false);

  int vertexc, edgec, queryc;
  cin >> vertexc >> edgec >> queryc;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
    merge(u, v);
  }

  for (int i = 1; i <= vertexc; i++) {
    comp_of[find(i)].push_back(i);
  }

  for (int i = 1; i <= vertexc; i++) {
    if (find(i) == i) {
      process_component(i);
    }
  }

  for (int i = 0; i < queryc; i++) {
    int u, v;
    cin >> u >> v;

    if (find(u) == find(v)) {
      cout << -1 << '\n';
    } else {
      cout << fixed << setprecision(12) << solve(u, v) << '\n';
    }
  }
}