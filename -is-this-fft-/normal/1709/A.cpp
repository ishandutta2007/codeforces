#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int x;
  cin >> x;

  vector<int> arr (4);
  for (int i = 1; i <= 3; i++) {
    cin >> arr[i];
  }

  int opened = 0;
  int cur = x;
  while (cur != 0) {
    cur = arr[cur];
    opened++;
  }

  cout << (opened == 3 ? "YES" : "NO") << '\n';
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