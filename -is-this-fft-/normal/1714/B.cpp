#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  set<int> seen;
  for (int i = n - 1; i >= 0; i--) {
    if (seen.count(arr[i])) {
      cout << i + 1 << '\n';
      return;
    }

    seen.insert(arr[i]);
  }

  cout << 0 << '\n';
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