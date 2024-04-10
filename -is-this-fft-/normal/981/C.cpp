#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

int deg [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    deg[u]++;
    deg[v]++;
  }

  vector<int> leaves;
  vector<int> centers;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 1) leaves.push_back(i);
    if (deg[i] > 2) centers.push_back(i);
  }

  if ((int) centers.size() > 1) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  cout << (leaves.size() + 1) / 2 << endl;
  for (int i = 0; i + 1 < (int) leaves.size(); i += 2) {
    cout << leaves[i] << " " << leaves[i + 1] << '\n';
  }
  if ((int) leaves.size() % 2 != 0) {
    cout << leaves.back() << " " << centers[0] << '\n';
  }
}