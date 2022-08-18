#include <iostream>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

int main () {
  int n, K;
  cin >> n >> K;

  if (K > n) {
    failure();
  }

  if (K == 1) {
    if (n == 1) {
      cout << "a" << endl;
      return 0;
    }
    failure();
  }

  int oths = K - 2;
  for (int i = 0; i < n - oths; i++) {
    if (i % 2 == 0) {
      cout << 'a';
    } else {
      cout << 'b';
    }
  }

  for (int i = 0; i < oths; i++) {
    cout << (char) ('c' + i);
  }
  cout << endl;
}