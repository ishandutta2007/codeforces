#include <iostream>
#include <stdlib.h>

const int MAX_VERT = 200005;

using namespace std;

int root [MAX_VERT];

int find (int u) {
  if (root[u] == u) {
    return u;
  } else {
    root[u] = find(root[u]);
    return root[u];
  }
}

void merge (int u, int v) {
  int uroot = find(u), vroot = find(v);
  
  if (uroot != vroot) {
    if (rand() % 2) {
      root[uroot] = vroot;
    } else {
      root[vroot] = uroot;
    }
  }
}

int main () {
  for (int i = 0; i < MAX_VERT; i++) {
    root[i] = i;
  }

  int skewerc;
  cin >> skewerc;

  for (int i = 1; i <= skewerc; i++) {
    int perm;
    cin >> perm;

    merge(i, perm);
  }

  int compc = 0;
  for (int i = 1; i <= skewerc; i++) {
    if (i == find(i)) {
      compc++;
    }
  }

  if (compc == 1) {
    compc--;
  }

  int onec = 0;
  for (int i = 0; i < skewerc; i++) {
    int flip;
    cin >> flip;

    if (flip == 1) {
      onec++;
    }
  }

  if (onec % 2 == 0) {
    compc++;
  }

  cout << compc << endl;
}