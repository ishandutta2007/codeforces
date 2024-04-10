#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int n;
  cin >> n;

  vector<char> c (n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  sort(c.begin(), c.end());

  for (int i = 0; i < n; i++) {
    cout << c[i];
  }
  cout << endl;
}