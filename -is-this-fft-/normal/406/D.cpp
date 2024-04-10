#include <iostream>
#include <vector>

typedef long long llong;

const int MAX_HILL = 100005;
const int MAX_PAR = 18;

using namespace std;

struct hill {
  llong x, y;
  int id;
} hills [MAX_HILL];

bool bslope (hill u, hill v, hill w) {
  return ((v.y - u.y) * (w.x - u.x) > (v.x - u.x) * (w.y - u.y));
}

int parent [MAX_HILL][MAX_PAR], lvl [MAX_HILL];

int lca (int p, int q) {
  if (lvl[p] != lvl[q]) {
    if (lvl[p] < lvl[q]) {
      swap(p, q);
    }

    int diff = lvl[p] - lvl[q];
    for (int i = 0; i < MAX_PAR; i++) {
      if (diff & 1 << i) {
        p = parent[p][i];
      }
    }
  }

  if (p == q) {
    return p;
  }

  for (int i = MAX_PAR - 1; i >= 0; i--) {
    if (parent[p][i] != parent[q][i]) {
      p = parent[p][i];
      q = parent[q][i];
    }
  }

  return parent[p][0];
}

int main () {
  int hillc;
  cin >> hillc;

  for (int i = 0; i < hillc; i++) {
    cin >> hills[i].x >> hills[i].y;
    hills[i].id = i;
  }

  lvl[hillc - 1] = 0;
  for (int i = 0; i < MAX_PAR; i++) {
    parent[hillc - 1][i] = hillc - 1;
  }
  
  /* construct the tree */
  vector<int> cur_hills;
  cur_hills.push_back(hillc - 1);
  for (int i = hillc - 2; i >= 0; i--) {
    while (cur_hills.size() >= 2) {
      if (bslope(hills[i], 
                 hills[cur_hills[cur_hills.size() - 2]], 
                 hills[cur_hills[cur_hills.size() - 1]])) {
        cur_hills.pop_back();
      } else {
        break;
      }
    }

    parent[i][0] = cur_hills.back();

    lvl[i] = lvl[parent[i][0]] + 1;
    for (int j = 1; j < MAX_PAR; j++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }

    cur_hills.push_back(i);
  }

  int queryc;
  cin >> queryc;

  for (int i = 0; i < queryc; i++) {
    int u, v;
    cin >> u >> v;

    cout << lca(u - 1, v - 1) + 1 << " ";
  }
  cout << endl;
}