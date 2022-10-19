#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> arr[i];
  }
  set<int> cur;
  int ans = 0;
  for (int el : arr) {
    if (cur.count(el)) {
      cur.erase(el);
    } else {
      cur.insert(el);
    }
    ans = max(ans, (int) cur.size());
  }
  cout << ans << endl;
}