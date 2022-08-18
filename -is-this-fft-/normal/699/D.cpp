#include <iostream>
#include <vector>

const int MAX_VERTEX = 200005;

using namespace std;

int parent [MAX_VERTEX];
int vis [MAX_VERTEX];

int main () {
  int verticec;
  cin >> verticec;

  for (int i = 1; i <= verticec; i++) {
    cin >> parent[i];
  }

  vector<int> roots (0);
  vector<int> srefs (0);
  for (int i = 1; i <= verticec; i++) {
    if (parent[i] == i) {
      srefs.push_back(i);
    }

    if (vis[i] == 0) {
      int cur = i;
      do {
        vis[cur] = 1;
        cur = parent[cur];
      } while (vis[cur] == 0);
      
      if (vis[cur] == 1) {
        roots.push_back(cur);
      }

      cur = i;
      do {
        vis[cur] = 2;
        cur = parent[cur];
      } while (vis[cur] != 2);
    }
  }

  if (srefs.size() == 0) {
    cout << (int) roots.size() << endl;

    for (int i = 0; i < (int) roots.size(); i++) {
      parent[roots[i]] = roots[0];
    }
  } else {
    cout << (int) roots.size() - 1 << endl;

    for (int i = 0; i < (int) roots.size(); i++) {
      parent[roots[i]] = srefs[0];
    }
  }


  for (int i = 1; i <= verticec; i++) {
    cout << parent[i] << " ";
  }
  cout << endl;
}