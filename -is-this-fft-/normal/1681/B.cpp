#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> deck (n);
  for (int i = 0; i < n; i++) {
    cin >> deck[i];
  }

  int m;
  cin >> m;

  int cur = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;

    cur += x;
    cur %= n;
  }

  cout << deck[cur] << '\n';
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