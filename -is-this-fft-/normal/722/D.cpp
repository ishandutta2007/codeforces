#include <iostream>
#include <set>

using namespace std;

set<int> taken;

int lfa (int u) {
  while (taken.count(u)) {
    u /= 2;
  }
  return u;
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    taken.insert(x);
  }

  while (true) {
    int bk = *taken.rbegin();
    int up = lfa(bk);
    if (up == 0) {
      break;
    }

    taken.erase(bk);
    taken.insert(up);
  }

  for (int u : taken) {
    cout << u << " ";
  }
  cout << '\n';
}