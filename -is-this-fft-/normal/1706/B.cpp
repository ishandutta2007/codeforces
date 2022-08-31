#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> cs (n);
  for (int i = 0; i < n; i++) {
    cin >> cs[i];
    cs[i]--;
  }

  vector<vector<int>> mx (n, vector<int> (2, 0));
  for (int i = 0; i < n; i++) {
    mx[cs[i]][i % 2] = 1 + mx[cs[i]][!(i % 2)];
  }

  for (int i = 0; i < n; i++) {
    cout << max(mx[i][0], mx[i][1]) << " ";
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