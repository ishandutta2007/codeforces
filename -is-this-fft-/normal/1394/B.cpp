#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

void failure () {
  cout << 0 << endl;
  exit(0);
}

vector<pair<int, int>> out_adj [MAX_N]; // <weight, target>
vector<pair<int, int>> conds [MAX_N]; // position, value

const int MAX_SQ = 100;
bool forb [MAX_SQ][MAX_SQ];
int idx (pair<int, int> cond) {
  return (cond.first - 1) * 10 + cond.second;
}

int ans;
int cur_forb [MAX_SQ];
void dfs (int cur, int K) {
  if (cur == K + 1) {
    ans++;
  } else {
    for (int i = 0; i < cur; i++) {
      int cur_idx = idx(make_pair(cur, i));
      if (!cur_forb[cur_idx]) {
        for (int j = 0; j < MAX_SQ; j++) {
          cur_forb[j] += forb[cur_idx][j];
        }
        dfs(cur + 1, K);
        for (int j = 0; j < MAX_SQ; j++) {
          cur_forb[j] -= forb[cur_idx][j];
        }
      }
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, m, K;
  cin >> n >> m >> K;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    out_adj[u].push_back(make_pair(w, v));
  }

  for (int i = 1; i <= n; i++) {
    sort(out_adj[i].begin(), out_adj[i].end());
    int sz = out_adj[i].size();
    for (int j = 0; j < sz; j++) {
      conds[out_adj[i][j].second].push_back(make_pair(sz, j));
    }
  }

  for (int i = 1; i <= n; i++) {
    vector<pair<int, int>> revconds;
    sort(conds[i].begin(), conds[i].end());
    pair<int, int> last = make_pair(-1, -1);

    for (int j = 0; j < (int) conds[i].size(); j++) {
      if (j != (int) conds[i].size() - 1 && conds[i][j] == conds[i][j + 1]) {
        cur_forb[idx(conds[i][j])]++;
      }
      if (conds[i][j] != last) {
        revconds.push_back(conds[i][j]);
      }
      last = conds[i][j];
    }

    if (revconds.empty()) failure();

    for (int j = 0; j < (int) revconds.size(); j++) {
      for (int k = j + 1; k < (int) revconds.size(); k++) {
        forb[idx(revconds[j])][idx(revconds[k])] = 1;
        forb[idx(revconds[k])][idx(revconds[j])] = 1;
      }
    }
  }

  dfs(1, K);
  cout << ans << endl;
}