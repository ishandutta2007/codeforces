#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int maxn = 100005;
vector<int> adj [maxn];

int main () {
  int vertexc, csum;
  cin >> vertexc >> csum;

  if (vertexc == 2) {
    cout << csum << endl;
    return 0;
  }

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int leafc = 0;
  for (int i = 1; i <= vertexc; i++) {
    if (adj[i].size() == 1) {
      leafc++;
    }
  }

  cout << fixed << setprecision(12) << 2 * (double) csum / leafc << endl;
}