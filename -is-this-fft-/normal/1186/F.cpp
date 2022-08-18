#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#define u first
#define v second

using namespace std;

int ceil (int p, int q) {
  return (p + q - 1) / q;
}

const int MAX_N = 1e6 + 5;

int deg [MAX_N];
int need [MAX_N];

void try_solve (int n, int m, const vector<pair<int, int>> &edges) {
  for (int i = 1; i <= n; i++) {
    need[i] = ceil(deg[i], 2);
  }

  int eleft = ceil(n + m, 2);

  vector<pair<int, int>> sol;
  vector<pair<int, int>> bkup;
  
  for (auto e : edges) {
    if (need[e.u] > 0 && need[e.v] > 0) {
      sol.push_back(e);
      eleft--;
      need[e.u]--;
      need[e.v]--;
    } else if (need[e.u] > 0 || need[e.v] > 0) {
      bkup.push_back(e);
    }
  }

  int dneed = 0;
  for (int i = 1; i <= n; i++) {
    dneed += need[i];
  }

  if (eleft < dneed) return;

  for (auto e : bkup) {
    if (need[e.u] > 0 || need[e.v] > 0) {
      sol.push_back(e);
      need[e.u]--;
      need[e.v]--;
    }
  }

  cout << (int) sol.size() << '\n';
  for (auto e : sol) {
    cout << e.u << " " << e.v << '\n';
  }
  exit(0);
}

int main () {
  mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

  int n, m;
  cin >> n >> m;
  
  vector<pair<int, int>> edges (m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v;
    deg[edges[i].u]++;
    deg[edges[i].v]++;
  }

  while (true) {
    shuffle(edges.begin(), edges.end(), rng);
    try_solve(n, m, edges);
  }
}