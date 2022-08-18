#include <iostream>

using namespace std;

int goodbit (int u, int v, int K) {
  int ans = 0;
  while (u % K <= v % K) {
    ans++;
    u /= K;
    v /= K;
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, K;
  cin >> n >> K;

  int cc = 1, kp = K;
  while (kp < n) {
    cc++;
    kp *= K;
  }

  cout << cc << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cout << 1 + goodbit(kp - i, kp - j, K) << " ";
    }
  }
  cout << endl;
}