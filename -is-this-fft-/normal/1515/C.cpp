#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 5;

void solve () {
  int n, m, X;
  cin >> n >> m >> X;

  set<pair<int, int>> towers; // <height, id>
  for (int i = 1; i <= m; i++) {
    towers.insert(make_pair(0, i));
  }

  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    
    auto add = *towers.begin();
    towers.erase(add);
    cout << add.second << " ";
    add.first += x;
    towers.insert(add);
  }
  cout << '\n';
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