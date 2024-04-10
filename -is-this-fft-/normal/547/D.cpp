#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 4e5 + 10;
const int YS = 2e5 + 5;

set<int> odds;
set<pair<int, int>> adj [MAX_N]; // <oth, idx>

char ans [MAX_N];
void direct (int idx, int u, int v) {
  if (u < v) {
    ans[idx] = 'b';
  } else {
    ans[idx] = 'r';
  }

  adj[u].erase(make_pair(v, idx));
  adj[v].erase(make_pair(u, idx));
}

void rem_odd (int u) {
  if ((int) adj[u].size() % 2 == 0) {
    odds.erase(u);
    return;
  }

  auto pr = *adj[u].begin();
  int idx = pr.second;
  int v = pr.first;
  direct(idx, u, v);
  rem_odd(v);
}

void rem (int u) {
  if (adj[u].empty()) {
    return;
  }

  auto pr = *adj[u].begin();
  int idx = pr.second;
  int v = pr.first;
  direct(idx, u, v);
  rem(v);
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    v += YS;

    adj[u].insert(make_pair(v, i));
    adj[v].insert(make_pair(u, i));
  }

  for (int i = 0; i < MAX_N; i++) {
    if (adj[i].size() % 2 == 1) {
      odds.insert(i);
    }
  }

  while (!odds.empty()) {
    int cur = *odds.begin();
    odds.erase(cur);
    rem_odd(cur);
  }

  for (int i = 0; i < MAX_N; i++) {
    rem(i);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << endl;
}