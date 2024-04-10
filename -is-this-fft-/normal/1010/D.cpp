#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_N = 1e6 + 5;

vector<int> adj [MAX_N];
char type [MAX_N];
int bit [MAX_N];

void calc_bit (int u) {
  if (adj[u].empty()) {
    return;
  }

  if (adj[u].size() == 1) {
    int v = adj[u][0];
    calc_bit(v);
    bit[u] = !bit[v];
    return;
  }
 
  int v = adj[u][0];
  int w = adj[u][1];
  calc_bit(v);
  calc_bit(w);

  if (type[u] == 'A') bit[u] = bit[v] & bit[w];
  if (type[u] == 'O') bit[u] = bit[v] | bit[w];
  if (type[u] == 'X') bit[u] = bit[v] ^ bit[w];
}

int flips [MAX_N];

void calc_flips (int u) {
  if (adj[u].empty()) {
    flips[u] = 1;
    return;
  }

  if (adj[u].size() == 1) {
    calc_flips(adj[u][0]);
    return;
  }

  int v = adj[u][0];
  int w = adj[u][1];

  if (type[u] == 'A') {
    if (bit[v] == 1) calc_flips(w);
    if (bit[w] == 1) calc_flips(v);
  } else if (type[u] == 'O') {
    if (bit[v] == 0) calc_flips(w);
    if (bit[w] == 0) calc_flips(v);
  } else if (type[u] == 'X') {
    calc_flips(w);
    calc_flips(v);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string t;
    cin >> t;

    type[i] = t[0];
    if (type[i] == 'I') {
      cin >> bit[i];
    } else if (type[i] == 'N') {
      int u;
      cin >> u;
      adj[i].push_back(u);
    } else {
      int u, v;
      cin >> u >> v;
      adj[i].push_back(u);
      adj[i].push_back(v);
    }
  }

  calc_bit(1);
  calc_flips(1);

  for (int i = 1; i <= n; i++) {
    if (type[i] == 'I') {
      cout << (bit[1] ^ flips[i]);
    }
  }
  cout << endl;
}