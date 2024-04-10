#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 3e5 + 5;

vector<int> adj [MAX_N];
int state [MAX_N]; // 0 - unexplored, 1 - teacher, 2 - student, 3 - ready!

set<int> readys;
void mark_ready (int u) {
  state[u] = 3;
  readys.insert(u);
}

void mark_student (int u) {
  readys.erase(u);
  state[u] = 2;
  for (int nxt : adj[u]) {
    if (state[nxt] != 1 && state[nxt] != 2) {
      mark_ready(nxt);
    }
  }
}

void mark_teacher (int u) {
  readys.erase(u);
  state[u] = 1;
  for (int nxt : adj[u]) {
    if (state[nxt] != 1 && state[nxt]!=2) {
      mark_student(nxt);
    }
  }
}

void solve () {
  int n, m;
  cin >> n >> m;
  
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    state[i] = 0;
  }
  readys.clear();

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  mark_teacher(1);

  while (!readys.empty()) {
    int cur = *readys.begin();
    mark_teacher(cur);
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (state[i] == 0) {
      cout << "NO" << '\n';
      return;
    } else if (state[i] == 1) {
      ans.push_back(i);
    }
  }

  cout << "YES" << '\n';
  cout << ans.size() << '\n';
  for (int u : ans) {
    cout << u << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}