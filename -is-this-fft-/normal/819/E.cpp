#include <iostream>
#include <vector>

using namespace std;

int main () {
  int n;
  cin >> n;

  vector<vector<int>> ans;

  if (n % 2 == 1) {
    ans.push_back({1, 2, 3});
    ans.push_back({1, 2, 3});
  } else {
    ans.push_back({1, 2, 3});
    ans.push_back({1, 2, 4});
    ans.push_back({1, 3, 4});
    ans.push_back({2, 3, 4});
  }

  for (int i = (n % 2 == 1) ? 5 : 6; i <= n; i += 2) {
    int u = i - 1;
    int v = i;
    for (int j = 1; j < i - 2; j++) {
      int a = j;
      int b = j + 1;

      ans.push_back({u, a, v, b});
    }
    ans.push_back({u, v, 1});
    ans.push_back({u, v, i - 2});
  }
  
  cout << (int) ans.size() << endl;
  for (auto v : ans) {
    cout << (int) v.size();
    for (int u : v) {
      cout << " " << u;
    }
    cout << '\n';
  }
}