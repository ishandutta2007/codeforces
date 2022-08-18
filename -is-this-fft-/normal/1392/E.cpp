#include <iostream>

using namespace std;

typedef long long ll;

void solve (ll K, int n) {
  int r = 0, c = 0;
  cout << r + 1 << " " << c + 1 << endl;
  for (int i = 1; i < 2 * n - 1; i++) {
    int oddcol = (K >> i) & 1;
    if (oddcol ^ (c % 2 == 1)) {
      c++;
    } else {
      r++;
    }

    cout << r + 1 << " " << c + 1 << endl;
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j % 2 == 1) {
        cout << (1LL << (i + j)) << " ";
      } else {
        cout << 0 << " ";
      }
    }
    cout << endl;
  }

  int qc;
  cin >> qc;
  for (int i = 0; i < qc; i++) {
    ll K;
    cin >> K;

    solve(K, n);
  }
}