#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  string s;
  cin >> s;
  vector<pair<int, int>> arr2(n);
  for (int i = 0; i < n; i++) {
    arr2[i].first = arr[i];
    arr2[i].second = i;
  }
  sort(arr2.begin(), arr2.end());
  set<pair<int, int>> used;
  int cur_ind = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '0') {
      used.insert(arr2[cur_ind]);
      cout << arr2[cur_ind++].second + 1 << " ";
    } else {
      cout << used.rbegin()->second + 1 << " ";
      used.erase(--used.end());
    }
  }
  cout << endl;
}