#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ptr = 0;
  for (int i = 0; i < K; i++) {
    while (ptr < n - 1 && arr[ptr] == 0) {
      ptr++;
    }

    if (ptr == n - 1) {
      break;
    }

    arr[ptr]--;
    arr[n - 1]++;
  }

  for (int u : arr) {
    cout << u << " ";
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