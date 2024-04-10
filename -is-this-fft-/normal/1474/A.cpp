#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  string B;
  cin >> B;

  int last = -1;
  for (int i = 0; i < n; i++) {
    int cur = B[i] - '0';
    if (cur + 1 == last) {
      cout << 0;
      last = cur;
    } else {
      cout << 1;
      last = cur + 1;
    }
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}