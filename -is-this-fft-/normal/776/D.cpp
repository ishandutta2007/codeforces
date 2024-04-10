#include <iostream>
#include <vector>

const int MAX_DOOR = 100005;
const int MAX_SWITCH = 100005;

using namespace std;

vector<int> parents [MAX_DOOR];
int open [MAX_DOOR];

struct edge {
  int vertex, col;
  
  edge () {
  }

  edge (int _v, int _c) {
    vertex = _v;
    col = _c;
  }

  void print () {
    cout << vertex << ";" << col << endl;
  }
};

vector<edge> adj [MAX_SWITCH];
int color [MAX_SWITCH];

bool dfs (int vertex, int col) {
  color[vertex] = col;

  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (color[adj[vertex][i].vertex] == 0) {
      if (!dfs(adj[vertex][i].vertex, col * adj[vertex][i].col)) {
        return false;
      }
    } else {
      if (color[adj[vertex][i].vertex] != col * adj[vertex][i].col) {
        return false;
      }
    }
  }

  return true;
}

int main () {
  int doorc, switchc;
  cin >> doorc >> switchc;

  for (int i = 1; i <= doorc; i++) {
    cin >> open[i];
  }

  for (int i = 0; i < switchc; i++) {
    int contc;
    cin >> contc;

    for (int j = 0; j < contc; j++) {
      int door;
      cin >> door;

      parents[door].push_back(i);
    }
  }

  for (int i = 1; i <= doorc; i++) {
    if (open[i] == 0) {
      adj[parents[i][0]].push_back(edge(parents[i][1], -1));
      adj[parents[i][1]].push_back(edge(parents[i][0], -1));
    } else {
      adj[parents[i][0]].push_back(edge(parents[i][1], 1));
      adj[parents[i][1]].push_back(edge(parents[i][0], 1));
    }
  }

  for (int i = 0; i < switchc; i++) {
    if (color[i] == 0) {
      if (dfs(i, 1) == false) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;
}