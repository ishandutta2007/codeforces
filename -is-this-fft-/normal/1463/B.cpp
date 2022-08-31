#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 55;

ll arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll ev = 0, od = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ev += arr[i] - 1;
    } else {
      od += arr[i] - 1;
    }
  }

  int ngt = 1;
  if (ev < od) {
    ngt = 0;
  }

  for (int i = 0; i < n; i++) {
    if (i % 2 == ngt) {
      cout << 1 << " ";
    } else {
      cout << arr[i] << " ";
    }
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}