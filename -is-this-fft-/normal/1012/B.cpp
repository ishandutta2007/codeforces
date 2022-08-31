#include <iostream>

const int MAX_H = 200005;
const int MAX_N = 2 * MAX_H + 5;

using namespace std;

int root [MAX_N];
int find (int u) {
  if (root[u] == u) {
    return root[u];
  } else {
    root[u] = find(root[u]);
    return root[u];
  }
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

int main () {
  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
  }
  
  int height, width, edgec;
  cin >> height >> width >> edgec;

  for (int i = 0; i < edgec; i++) {
    int row, col;
    cin >> row >> col;

    merge(row, MAX_H + col);
  }

  int connc = 0;
  for (int i = 1; i <= height; i++) {
    if (find(i) == i) {
      connc++;
    }
  }

  for (int i = 1; i <= width; i++) {
    if (find(MAX_H + i) == MAX_H + i) {
      connc++;
    }
  }

  cout << connc - 1 << endl;
}