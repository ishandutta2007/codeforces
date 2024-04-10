#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

void failure () {
  cout << -1 << endl;
  exit(0);
}

int color [MAX_N];
vector<int> adj [MAX_N];

void dfs (int u, int c) {
  color[u] = c;
  for (int nxt : adj[u]) {
    if (color[nxt] == 0) dfs(nxt, -c);
    else if (color[nxt] == c) failure();
  }
}

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (color[i] == 0) {
      dfs(i, 1);
    }
  }

  vector<int> A, B;
  for (int i = 1; i <= n; i++) {
    if (color[i] == 1) A.push_back(i);
    else B.push_back(i);
  }

  cout << (int) A.size() << endl;
  for (int a : A) {
    cout << a << " ";
  }
  cout << '\n';

  cout << (int) B.size() << endl;
  for (int b : B) {
    cout << b << " ";
  }
  cout << '\n';
}