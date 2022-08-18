#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> num;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;

    num.push_back(c - '0');
  }
  reverse(num.begin(), num.end()); // big-endian

  vector<int> sum;
  if (num.back() == 9) {
    sum = vector<int> (n + 1, 1);
  } else {
    sum = vector<int> (n, 9);
  }

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (sum[i] - num[i] < 0) {
      sum[i] += 10;
      sum[i + 1]--;
    }

    ans.push_back(sum[i] - num[i]);
  }

  reverse(ans.begin(), ans.end());
  for (int u : ans) {
    cout << u;
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