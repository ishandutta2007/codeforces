#include <iostream>
#include <set>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  if (n == 4 && K == 3) {
    cout << -1 << '\n';
    return;
  }
  
  int mask = n - 1;
  set<int> special;
  if (K == n - 1) {
    cout << n - 1 << " " << n - 2 << '\n';
    cout << 1 << " " << 3 << '\n';
    cout << n - 4 << " " << 0 << '\n';
    special.insert(n - 1);
    special.insert(n - 2);
    special.insert(1);
    special.insert(3);
    special.insert(n - 4);
    special.insert(0);
  } else if (K > 0) {
    int invK = (~K) & mask;
    cout << n - 1 << " " << K << '\n';
    cout << invK << " " << 0 << '\n';
    special.insert(n - 1);
    special.insert(K);
    special.insert(invK);
    special.insert(0);
  }
  
  for (int i = 0; i < n; i++) {
    int oth = (~i) & mask;
    if (i < oth && !special.count(i)) {
      cout << i << " " << oth << '\n';
    }
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}