#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

int perm [MAX_N];

int vis [MAX_N];
vector<vector<int>> cycles;
void dfs (int u) {
  if (vis[u]) return;
  vis[u] = 1;
  cycles.back().push_back(u);
  dfs(perm[u]);
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> perm[i];
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cycles.push_back(vector<int> (0));
      dfs(i);
    }
  }

  int sngl_id = -1;
  int dbl_id = -1;
  int all_even = 1;
  for (int i = 0; i < (int) cycles.size(); i++) {
    if ((int) cycles[i].size() == 1) {
      sngl_id = i;
    }

    if ((int) cycles[i].size() == 2) {
      dbl_id = i;
    }

    if ((int) cycles[i].size() % 2 != 0) {
      all_even = 0;
    }
  }

  if (sngl_id != -1) {
    cout << "YES" << endl;
    for (int i = 0; i < (int) cycles.size(); i++) {
      if (i != sngl_id) {
        for (int u : cycles[i]) {
          cout << cycles[sngl_id][0] << " " << u << '\n';
        }
      }
    }
  } else if (dbl_id != -1 && all_even) {
    cout << "YES" << endl;
    cout << cycles[dbl_id][0] << " " << cycles[dbl_id][1] << '\n';
    for (int i = 0; i < (int) cycles.size(); i++) {
      if (i != dbl_id) {
        for (int j = 0; j < (int) cycles[i].size(); j++) {
          cout << cycles[dbl_id][j % 2] << " " << cycles[i][j] << '\n';
        }
      }
    }
  } else {
    cout << "NO" << endl;
  }
}