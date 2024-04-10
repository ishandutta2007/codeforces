#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int marked [MAX_N];

void build_mark (int vertex, int parent) {
  if ((int) adj[vertex].size() == 1) {
    marked[vertex] = 1;
  }

  int mc = 0, umc = 0;
  for (int nxt : adj[vertex]) {
    if (nxt != parent) {
      build_mark(nxt, vertex);
      if (marked[nxt]) mc++;
      else umc++;
    }
  }

  if (mc == 1 && umc == 0) {
    marked[vertex] = 1;
  }
}

int cater [MAX_N];
void mark_cater (int vertex) {
  int nmc = 0, mc = 0;
  for (int u : adj[vertex]) {
    if (!marked[u]) {
      nmc++;
    } else {
      mc++;
    }
  }

  if (nmc <= 1 && mc <= 2) {
    cater[vertex] = 1;
  }
}

void check_chain (int vertex) {
  int umc = 0;
  for (int u : adj[vertex]) {
    if (!marked[u] && !cater[u]) {
      umc++;
    }
  }

  if (umc > 2) {
    cout << "No" << endl;
    exit(0);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc;
  cin >> vertexc;
  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  pair<int, int> root = {-1, -1};
  for (int i = 1; i <= vertexc; i++) {
    root = max(root, make_pair((int) adj[i].size(), i));
  }

  if (root.first <= 2) {
    cout << "Yes" << endl;
    return 0;
  }

  int treer = root.second;
  build_mark(treer, treer);

  for (int i = 1; i <= vertexc; i++) {
    if (!marked[i]) {
      mark_cater(i);
    }
  }

  for (int i = 1; i <= vertexc; i++) {
    if (!marked[i] && !cater[i]) {
      check_chain(i);
    }
  }

  cout << "Yes" << endl;
}