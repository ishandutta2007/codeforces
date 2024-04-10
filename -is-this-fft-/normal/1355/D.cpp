#include <iostream>

using namespace std;

int main () {
  int n, S;
  cin >> n >> S;

  if (n == 1) {
    if (S > 1) {
      cout << "YES" << endl << S << endl << 1 << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
  }

  if (S - (n - 1) <= n) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  for (int i = 0; i < n - 1; i++) {
    cout << 1 << " ";
  }
  cout << S - (n - 1) << '\n';
  cout << n << '\n';
}