#include <iostream>
#include <stdlib.h>

const int MAX_VERTICE = 10005;

using namespace std;

int root [MAX_VERTICE];

int find (int u) {
  if (root[u] == u) {
    return u;
  } else {
    root[u] = find(root[u]);
    return root[u];
  }
}

void merge (int u, int v) {
  if (find(u) != find(v)) {
    if (rand() % 2 == 0) {
      root[find(u)] = v;
    } else {
      root[find(v)] = u;
    }
  }
}

int main () {
  int peoplec;
  cin >> peoplec;

  for (int i = 0; i < MAX_VERTICE; i++) {
    root[i] = i;
  }

  for (int i = 1; i <= peoplec; i++) {
    int u;
    cin >> u;
    
    merge(u, i);
  }

  int ans = 0;
  for (int i = 1; i <= peoplec; i++) {
    if (find(i) == i) {
      ans++;
    }
  }
  cout << ans << endl;
}