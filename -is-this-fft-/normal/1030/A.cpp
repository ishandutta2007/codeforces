#include <iostream>

using namespace std;

int main () {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    ans |= x;
  }

  cout << (ans == 0 ? "EASY" : "HARD") << '\n';
}