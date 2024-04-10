#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> add [10] =
  {{}, {}, {2}, {3}, {2, 2, 3}, {5}, {5, 3}, {7}, {7, 2, 2, 2}, {7, 3, 3, 2}};

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    arr.push_back((int) c - '0');
  }

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int u : add[arr[i]]) {
      ans.push_back(u);
    }
  }

  sort(ans.begin(), ans.end(), greater<int> ());

  for (int u : ans) {
    cout << u;
  }
  cout << endl;
}