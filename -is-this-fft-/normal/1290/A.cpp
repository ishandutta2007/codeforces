#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 3505;

int arr [MAX_N];

void solve () {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> choices;
  for (int i = 0; i < m; i++) {
    choices.push_back(max(arr[i], arr[i + n - m]));
  }
  
  int ans = 0;
  for (int i = 0; i <= min(m - 1, k); i++) {
    int r = i + (m - k);
    r = min(r, m);
    if (r <= i) r = i + 1;
    
    int cur = 1e9 + 5;
    for (int j = i; j < r; j++) {
      cur = min(cur, choices[j]);
    }
    ans = max(ans, cur);
  }

  cout << ans << endl;
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}