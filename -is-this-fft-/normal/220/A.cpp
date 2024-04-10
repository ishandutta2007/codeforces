#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a (n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b = a;
  sort(b.begin(), b.end());

  int diff = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      diff++;
    }
  }

  if (diff <= 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}