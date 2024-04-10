#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 5;

vector<int> adj [MAX_N];
int lvl [MAX_N];
int par [MAX_N];
int intern [MAX_N];

void dfs (int u, int p) {
  lvl[u] = lvl[p] + 1;
  par[u] = p;
  for (int nxt : adj[u]) {
    if (lvl[nxt] == 0) {
      intern[u] = 1;
      dfs(nxt, u);
    }
  }
}

void print_cyc (int u) {
  vector<int> ancs;
  for (int nxt : adj[u]) {
    if (nxt != par[u]) {
      ancs.push_back(nxt);
    }
  }

  int a = ancs[0];
  int b = ancs[1];
  if (lvl[a] < lvl[b]) swap(a, b);
  int da = lvl[u] - lvl[a];
  int db = lvl[a] - lvl[b];

  vector<int> ans;
  if ((da + 1) % 3 != 0) {
    for (int i = u; true; i = par[i]) {
      ans.push_back(i);
      if (i == a) break;
    }
  } else if ((db + 2) % 3 != 0) {
    ans.push_back(u);
    for (int i = a; true; i = par[i]) {
      ans.push_back(i);
      if (i == b) break;
    }
  } else {
    for (int i = u; true; i = par[i]) {
      ans.push_back(i);
      if (i == b) break;
    }
  }

  cout << (int) ans.size() << '\n';
  for (int u : ans) {
    cout << u << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 1);

  int target = (n + k - 1) / k;
  for (int i = 1; i <= n; i++) {
    if (lvl[i] >= target) {
      cout << "PATH" << endl;
      cout << lvl[i] << endl;
      for (int u = i; true; u = par[u]) {
        cout << u << " ";
        if (u == 1) break;
      }
      cout << '\n';
      return 0;
    }
  }

  cout << "CYCLES" << '\n';
  int printed = 0;
  for (int i = 1; i <= n && printed < k; i++) {
    if (!intern[i]) {
      print_cyc(i);
      printed++;
    }
  }
}