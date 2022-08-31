#include <iostream>

using namespace std;

bool win (int c1, int c0) {
  if (c1 % 4 == 1) return true;
  if (c0 % 2 == 1) return true;
  return false;
}

const int MAX_N = 1e5 + 5;
const int MAX_LG = 30;
int arr [MAX_N];

void solve () {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = MAX_LG; i >= 0; i--) {
    int c1 = 0, c0 = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j] & 1 << i) {
        c1++;
      } else {
        c0++;
      }
    }

    if (c1 % 2 == 1) {
      if (win(c1, c0)) {
        cout << "WIN" << '\n';
      } else {
        cout << "LOSE" << '\n';
      }
      return;
    }
  }
  cout << "DRAW" << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}