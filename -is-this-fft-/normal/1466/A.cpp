#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 55;

int arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  set<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans.insert(arr[j] - arr[i]);
    }
  }

  cout << (int) ans.size() << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}