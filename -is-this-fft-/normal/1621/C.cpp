#include <iostream>
#include <vector>

using namespace std;

int ask (int i) {
  cout << "? " << i << endl;

  int resp;
  cin >> resp;
  return resp;
}

const int MAX_N = 1e4 + 5;

int nxt [MAX_N];
bool vis [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;

    vector<int> cycle;
    while (true) {
      int cur = ask(i);
      cycle.push_back(cur);

      if ((int) cycle.size() > 1 && cycle[0] == cycle.back()) {
        break;
      }
    }

    for (int j = 0; j < (int) cycle.size() - 1; j++) {
      nxt[cycle[j]] = cycle[j + 1];
      vis[cycle[j]] = 1;
    }
  }

  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << nxt[i] << " ";
  }
  cout << endl;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}