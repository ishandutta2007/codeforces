#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = n - 1; i > 0; i--) {
    arr[i] -= arr[i - 1];
  }

  set<pair<int, int>> cur; // <value, index>
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      cur.insert({arr[i], i});
    }
  }

  vector<int> ans (n);
  for (int k = n; k >= 1; k--) {
    if (cur.empty()) {
      ans[k - 1] = 0;
    } else {
      auto pr = *cur.begin();
      cur.erase(pr);
      int idx = pr.second;
      arr[idx] += k;
      if (arr[idx] < 0) {
        cur.insert({arr[idx], idx});
      }
      ans[k - 1] = idx;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << 1 + ans[i] << " ";
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