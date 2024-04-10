#include <iostream>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 1e5 + 5;

int arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  int cn = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] < 0) {
      cn++;
      arr[i] *= -1;
    }
  }

  int last = INF, ncur = 0, state = 0;
  int nneg = 0, nmay = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == last) {
      ncur++;
      continue;
    }

    if (arr[i] < last && state == 0) {
      ncur = 1;
      last = arr[i];
      continue;
    }

    if (arr[i] > last && state == 1) {
      ncur = 1;
      last = arr[i];
      continue;
    }

    if (arr[i] > last && state == 0) {
      nmay = ncur;
      nneg = i - nmay;
      
      ncur = 1;
      last = arr[i];
      state = 1;
      continue;
    }

    cout << "NO" << '\n';
    return;
  }

  if (state == 0) {
    nmay = ncur;
    nneg = n - nmay;
  }

  if (nneg <= cn && cn <= nneg + nmay) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
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