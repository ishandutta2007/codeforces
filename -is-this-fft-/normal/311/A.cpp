#include <iostream>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  if (K >= (n * (n - 1)) / 2) {
    cout << "no solution" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    cout << 0 << " " << i << '\n';
  }
}