#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << "Division ";
    if (n <= 1399) {
      cout << "4\n";
      continue;
    }
    if (n <= 1599) {
      cout << "3\n";
      continue;
    }
    if (n <= 1899) {
      cout << "2\n";
      continue;
    }
    cout << "1\n";
  }
}