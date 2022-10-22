#include <iostream>
#include <set>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  set<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    arr.insert(x);
  }

  for (int u : arr) {
    if (arr.count(u + K)) {
      cout << "YES" << '\n';
      return;
    }
  }

  cout << "NO" << '\n';
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