#include <iostream>
#include <vector>

using namespace std;

const int BIG = 1e9;

bool can (vector<int> arr, int K, int M) {
  if (M > BIG) return false;

  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if (2 * arr[i] < M) {
      K--;
      arr[i] = BIG;
    }
  }

  bool found = false;
  for (int i = 0; i < n - 1; i++) {
    if (min(arr[i], arr[i + 1]) >= M) {
      found = true;
    }
  }

  if (found) {
    return K >= 0;
  }

  bool found2 = false;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= M) {
      found2 = true;
    }
  }

  if (found2) {
    return K >= 1;
  }

  return K >= 2;
}

void solve () {
  int n, K;
  cin >> n >> K;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ans = 0;
  for (int k = 1 << 29; k != 0; k /= 2) {
    if (can(arr, K, ans + k)) {
      ans += k;
    }
  }

  cout << ans << '\n';
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