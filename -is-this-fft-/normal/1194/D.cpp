#include <iostream>

using namespace std;

void solve () {
  int length, K;
  cin >> length >> K;

  if (K % 3 != 0) {
    if (length % 3 == 0) {
      cout << "Bob" << '\n';
    } else {
      cout << "Alice" << '\n';
    }
  } else {
    int val = length % (K + 1);
    if (val > K - 3) {
      cout << "Alice" << '\n';
    } else {
      if (val % 3 == 0) {
        cout << "Bob" << '\n';
      } else {
        cout << "Alice" << '\n';
      }
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}