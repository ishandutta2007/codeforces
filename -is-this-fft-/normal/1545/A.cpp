#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

void solve () {
  int n;
  cin >> n;

  vector<int> even;
  vector<int> odd;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (i % 2 == 0) {
      even.push_back(x);
    } else {
      odd.push_back(x);
    }
  }

  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end());

  vector<int> merged;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      merged.push_back(even[i / 2]);
    } else {
      merged.push_back(odd[i / 2]);
    }
  }

  for (int i = 0; i < n - 1; i++) {
    if (merged[i + 1] < merged[i]) {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
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