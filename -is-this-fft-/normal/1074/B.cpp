#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxn = 1005;

int aska (int q) {
  cout << "A " << q << endl;
  int ans;
  cin >> ans;

  if (ans == -1) {
    exit(0);
  }
  return ans;
}

int askb (int q) {
  cout << "B " << q << endl;
  int ans;
  cin >> ans;

  if (ans == -1) {
    exit(0);
  }
  return ans;
}

void report (int q) {
  cout << "C " << q << endl;
}

vector<int> adj [maxn];
int cum [maxn];
int lc;

void dfs (int vertex, int parent, int target) {
  for (int nxt : adj[vertex]) {
    if (nxt != parent) {
      dfs(nxt, vertex, target);
      cum[vertex] += cum[nxt];
    }
  }
  
  if (cum[vertex] == target && lc == -1) {
    lc = vertex;
  }
}

void solve () {
  for (int i = 0; i < maxn; i++) {
    adj[i].clear();
    cum[i] = 0;
  }
  lc = -1;

  int vertexc;
  cin >> vertexc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int alicec;
  cin >> alicec;
  for (int i = 0; i < alicec; i++) {
    int u;
    cin >> u;
    cum[u]++;
  }

  int bobc;
  cin >> bobc;
  set<int> bob;
  for (int i = 0; i < bobc; i++) {
    int u;
    cin >> u;
    bob.insert(u);
  }

  int root = askb(*bob.begin());
  dfs(root, 0, alicec);

  int boblc = aska(lc);
  if (bob.count(boblc) == 1) {
    report(lc);
  } else {
    report(-1);
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;
  for (int t = 0; t < testc; t++) {
    solve();
  }
}