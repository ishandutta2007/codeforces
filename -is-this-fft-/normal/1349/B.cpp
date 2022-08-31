#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

void solve () {
  int n, k;
  cin >> n >> k;

  int ex = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == k) ex = 1;
    arr[i] = (arr[i] >= k);
  }

  if (!ex) {
    cout << "no" << '\n';
    return;
  }

  if (n == 1 && ex) {
    cout << "yes" << '\n';
    return;
  }
  
  int flag = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i]) {
      if (arr[i - 1]) flag = 1;
      if (i - 2 >= 0 && arr[i - 2]) flag = 1;
    }
  }

  if (flag) {
    cout << "yes" << '\n';
  } else {
    cout << "no" << '\n';
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