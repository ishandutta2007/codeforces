#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define x first
#define y second

void solve () {
  int n;
  cin >> n;

  vector<int> a (n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b (n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  vector<pair<pair<int, int>, int>> arr (n);
  for (int i = 0; i < n; i++) {
    arr[i] = {{a[i], b[i]}, i};
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n - 1; i++) {
    if (arr[i].x.x > arr[i + 1].x.x ||
        arr[i].x.y > arr[i + 1].x.y) {
      cout << -1 << '\n';
      return;
    }
  }

  vector<pair<int, int>> sarr (n);
  for (int i = 0; i < n; i++) {
    sarr[i] = {a[i], b[i]};
  }
  
  vector<pair<int, int>> ans;
  while (true) {
    bool found = false;
    for (int i = 0; i < n - 1; i++) {
      if (sarr[i] > sarr[i + 1]) {
        ans.push_back({i, i + 1});
        swap(sarr[i], sarr[i + 1]);
        found = true;
      }
    }

    if (!found) {
      break;
    }
  }

  cout << (int) ans.size() << '\n';
  for (auto pr : ans) {
    cout << 1 + pr.x << " " << 1 + pr.y << '\n';
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