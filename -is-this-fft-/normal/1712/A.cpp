#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  vector<int> perm (n);
  for (int i = 0; i < n; i++) {
    cin >> perm[i];
  }

  int ans = 0;
  for (int i = 0; i < K; i++) {
    if (perm[i] > K) {
      ans++;
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