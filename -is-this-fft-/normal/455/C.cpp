#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

const int INF = 1023456789;
const int MAX_CITY = 300005;

using namespace std;

int root [MAX_CITY], diam [MAX_CITY];

int find (int u) {
  if (root[u] == u) {
    return u;
  } else {
    root[u] = find(root[u]);
    return root[u];
  }
}

void merge_simple (int u, int v) {
  if (find(u) != find(v)) {
    if (rand() % 2) {
      root[find(u)] = find(v);
    } else {
      root[find(v)] = find(u);
    }
  }
}

void merge (int u, int v) {
  if (find(u) != find(v)) {
    int newd = max(max(diam[find(u)],
                       diam[find(v)]),
                   (diam[find(u)] + 1) / 2 + (diam[find(v)] + 1) / 2 + 1);
    if (rand() % 2) {
      root[find(u)] = find(v);
      diam[find(v)] = newd;
    } else {
      root[find(v)] = find(u);
      diam[find(u)] = newd;
    }
  }
}

int dist1 [MAX_CITY], dist2 [MAX_CITY];
vector<int> adj [MAX_CITY];

int main () {
  for (int i = 0; i < MAX_CITY; i++) {
    root[i] = i;
    dist1[i] = INF;
    dist2[i] = INF;
  }

  ios::sync_with_stdio(false);

  int cityc, edgec, queryc;
  cin >> cityc >> edgec >> queryc;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    merge_simple(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= cityc; i++) {
    if (find(i) == i) {
      queue<int> que;
      que.push(i);
      dist1[i] = 0;

      int farthest = i, farthestd = 0;
      while (!que.empty()) {
        int qtop = que.front();
        que.pop();

        if (dist1[qtop] > farthestd) {
          farthestd = dist1[qtop];
          farthest = qtop;
        }

        for (int j = 0; j < (int) adj[qtop].size(); j++) {
          if (dist1[adj[qtop][j]] == INF) {
            dist1[adj[qtop][j]] = dist1[qtop] + 1;
            que.push(adj[qtop][j]);
          }
        }
      }

      queue<int> que2;
      que2.push(farthest);
      dist2[farthest] = 0;

      while (!que2.empty()) {
        int qtop = que2.front();
        que2.pop();

        diam[find(i)] = max(diam[find(i)], dist2[qtop]);

        for (int j = 0; j < (int) adj[qtop].size(); j++) {
          if (dist2[adj[qtop][j]] == INF) {
            dist2[adj[qtop][j]] = dist2[qtop] + 1;
            que2.push(adj[qtop][j]);
          }
        }
      }
    }
  }

  for (int i = 0; i < queryc; i++) {
    int query;
    cin >> query;

    if (query == 1) {
      int u;
      cin >> u;

      cout << diam[find(u)] << '\n';
    } else {
      int u, v;
      cin >> u >> v;

      merge(u, v);
    }
  }
}