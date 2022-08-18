#include <iostream>
#include <vector>
#include <string>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];
vector<int> rev [MAX_N];

int cyc [MAX_N];
void dfs (int u) {
  cyc[u] = 1;

  for (int nxt : adj[u]) {
    if (cyc[nxt] == 0) {
      dfs(nxt);
    } else if (cyc[nxt] == 1) {
      failure();
    }
  }
  
  cyc[u] = 2;
}

int a_vis [MAX_N];
void a_mark (int u) {
  if (a_vis[u]) return;
  a_vis[u] = 1;

  for (int nxt : adj[u]) {
    a_mark(nxt);
  }
}

int r_vis [MAX_N];
void r_mark (int u) {
  if (r_vis[u]) return;
  r_vis[u] = 1;

  for (int nxt : rev[u]) {
    r_mark(nxt);
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    rev[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (cyc[i] == 0) dfs(i);
  }

  int allc = 0;
  vector<char> ans;
  for (int i = 1; i <= n; i++) {
    if (a_vis[i] || r_vis[i]) {
      ans.push_back('E');
    } else {
      ans.push_back('A');
      allc++;
    }

    a_mark(i);
    r_mark(i);
  }

  cout << allc << endl;
  for (char c : ans) {
    cout << c;
  }
  cout << endl;
}