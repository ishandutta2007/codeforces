#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n, Q;
  cin >> n >> Q;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> ans (n, 0);
  int cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] > cur) {
      if (cur < Q) {
        cur++;
        ans[i] = 1;
      }
    } else {
      ans[i] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i];
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