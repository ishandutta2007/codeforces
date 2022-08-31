#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 5e5 + 5;

int repr [MAX_N]; // leftmost appearance of color i
int root [MAX_N];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[v] = u;
}

int main () {
  for (int i = 0; i < MAX_N; i++) {
    repr[i] = -1;
    root[i] = i;
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int qc;
  cin >> qc;

  int len = 0;
  for (int i = 0; i < qc; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;

      if (repr[x] == -1) {
        repr[x] = len;
      } else {
        merge(repr[x], len);
      }
      len++;
    } else {
      int x, y;
      cin >> x >> y;

      if (x == y) continue;
      if (repr[x] != -1 && repr[y] != -1) {
        merge(min(repr[x], repr[y]), max(repr[x], repr[y]));
        repr[y] = min(repr[x], repr[y]);
        repr[x] = -1;
      } else if (repr[x] != -1) {
        repr[y] = repr[x];
        repr[x] = -1;
      }
      // otherwise nothing changes
    }
  }

  map<int, int> irepr;
  for (int i = 0; i < MAX_N; i++) {
    if (repr[i] != -1) {
      irepr[repr[i]] = i;
    }
  }

  for (int i = 0; i < len; i++) {
    cout << irepr[find(i)] << " ";
  }
  cout << '\n';
}