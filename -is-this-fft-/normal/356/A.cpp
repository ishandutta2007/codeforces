#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 5;

int winner [MAX_N];
set<int> alive;

void tournament (int l, int r, int x) {
  vector<int> to_del;
  for (auto it = alive.lower_bound(l); it != alive.end() && *it <= r; it++) {
    if (*it != x) {
      winner[*it] = x;
      to_del.push_back(*it);
    }
  }

  for (int u : to_del) {
    alive.erase(u);
  }
}

int main () {
  int n, qc;
  cin >> n >> qc;

  for (int i = 1; i <= n; i++) {
    alive.insert(i);
  }

  for (int i = 0; i < qc; i++) {
    int l, r, x;
    cin >> l >> r >> x;

    tournament(l, r, x);
  }

  for (int i = 1; i <= n; i++) {
    cout << winner[i] << " ";
  }
  cout << endl;
}