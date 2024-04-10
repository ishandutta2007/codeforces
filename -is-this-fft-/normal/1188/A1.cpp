#include <iostream>

using namespace std;

const int MAX_N = 100005;

int deg [MAX_N];

int main () {
  int vertexc;
  cin >> vertexc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    deg[u]++;
    deg[v]++;
  }

  for (int i = 1; i <= vertexc; i++) {
    if (deg[i] == 2) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout<< "YES" << endl;
}