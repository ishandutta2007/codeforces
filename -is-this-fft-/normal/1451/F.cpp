#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 105;

int grid [MAX_N][MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  vector<int> xors (n + m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;

      xors[i + j] ^= x;
    }
  }

  bool allz = true;
  for (int i = 0; i < n + m; i++) {
    if (xors[i] != 0) {
      allz = false;
    }
  }

  if (allz) {
    cout << "Jeel" << '\n';
  } else {
    cout << "Ashish" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}