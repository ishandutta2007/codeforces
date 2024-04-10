#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <vector>

const int MAX_WORD = 100005;

using namespace std;

int root [MAX_WORD];

int find (int vertex) {
  if (root[vertex] == vertex) {
    return vertex;
  } else {
    root[vertex] = find(root[vertex]);
    return root[vertex];
  }
}

void merge (int u, int v) {
  if (find(u) != find(v)) {
    if (rand() % 2) {
      root[find(u)] = find(v);
    } else {
      root[find(v)] = find(u);
    }
  }
}

vector<pair<int, int> > adj [MAX_WORD];

int color [MAX_WORD];
void dfs (int vertex, int col) {
  color[vertex] = col;

  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (color[adj[vertex][i].first] == 0) {
      if (adj[vertex][i].second == 1) {
        dfs(adj[vertex][i].first, col);
      } else {
        dfs(adj[vertex][i].first, -col);
      }
    }
  }
}

int main () {
  for (int i = 0; i < MAX_WORD; i++) {
    root[i] = i;
  }

  int wordc, edgec, queryc;
  cin >> wordc >> edgec >> queryc;

  map<string, int> compr;
  for (int i = 0; i < wordc; i++) {
    string word;
    cin >> word;

    compr[word] = i;
  }

  vector<pair<int, pair<int, int> > > edges;
  for (int i = 0; i < edgec; i++) {
    int polar;
    cin >> polar;

    string u, v;
    cin >> u >> v;

    int uc = compr[u], vc = compr[v];
    edges.push_back(make_pair(polar, make_pair(uc, vc)));

    if (find(uc) != find(vc)) {
      merge(uc, vc);
      adj[uc].push_back(make_pair(vc, polar));
      adj[vc].push_back(make_pair(uc, polar));
    }
  }

  for (int i = 0; i < wordc; i++) {
    if (color[i] == 0) {
      dfs(i, 1);
    }
  }

  for (int i = 0; i < edgec; i++) {
    if (edges[i].first == 1) {
      if (color[edges[i].second.first] == color[edges[i].second.second]) {
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    } else {
      if (color[edges[i].second.first] != color[edges[i].second.second]) {
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }

  for (int i = 0; i < queryc; i++) {
    string u, v;
    cin >> u >> v;

    int uc = compr[u], vc = compr[v];
    if (find(uc) != find(vc)) {
      cout << 3 << "\n";
    } else if (color[uc] == color[vc]) {
      cout << 1 << "\n";
    } else {
      cout << 2 << "\n";
    }
  }
}