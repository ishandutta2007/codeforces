#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2 != 0) {
    cout << "NO";
  } else if (n <= 2) {
    cout << "NO";
  } else {
    cout << "YES" << endl;
  }
  cout << endl;
}