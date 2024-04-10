#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> b = arr;
  sort(b.begin(), b.end());

  if (arr == b) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
  }
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