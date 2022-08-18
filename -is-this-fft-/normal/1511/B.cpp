#include <iostream>

using namespace std;

int pw (int a, int k) {
  int ans = 1;
  for (int i = 0; i < k; i++) {
    ans *= a;
  }
  return ans;
}

void solve () {
  int a, b, c;
  cin >> a >> b >> c;

  cout << pw(11, a - 1) << " " << pw(11, c - 1) * pw(10, b - c) << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}