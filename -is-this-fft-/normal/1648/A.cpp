#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_C = 1e5 + 5;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr (n, vector<int> (m, 0));
  vector<int> cnt (MAX_C, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      cnt[arr[i][j]]++;
    }
  }

  vector<int> cur (MAX_C, 0);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += (ll) i * cur[arr[i][j]];
      ans -= (ll) i * (cnt[arr[i][j]] - cur[arr[i][j]] - 1);
      cur[arr[i][j]]++;
    }
  }

  cur = vector<int> (MAX_C, 0);
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      ans += (ll) j * cur[arr[i][j]];
      ans -= (ll) j * (cnt[arr[i][j]] - cur[arr[i][j]] - 1);
      cur[arr[i][j]]++;      
    }
  }

  cout << ans << '\n';
}