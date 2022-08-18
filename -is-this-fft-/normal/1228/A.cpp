#include <iostream>
#include <vector>

using namespace std;

bool all_diff (int x) {
  vector<int> dig (10, 0);
  while (x != 0) {
    dig[x % 10]++;
    x /= 10;
  }

  for (int i = 0; i < 10; i++) {
    if (dig[i] > 1) return false;
  }
  return true;
}

int main () {
  ios::sync_with_stdio(false);

  int l, r;
  cin >> l >> r;

  for (int i = l; i <= r; i++) {
    if (all_diff(i)) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}