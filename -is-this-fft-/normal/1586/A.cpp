#include <iostream>

using namespace std;

const int MAX_S = 2e4 + 5;
const int MAX_N = 105;

int sieve [MAX_S];
int arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  if (sieve[sum]) {
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << 1 + i << " ";
    }
    cout << '\n';
    return;
  }

  bool found = false;
  cout << n - 1 << '\n';
  for (int i = 0; i < n; i++) {
    if (!found && arr[i] % 2 == 1) {
      found = true;
      continue;
    }

    cout << 1 + i << " ";
  }
  cout << '\n';
}

int main () {
  for (int i = 2; i < MAX_S; i++) {
    if (!sieve[i]) {
      for (int j = 2 * i; j < MAX_S; j += i) {
        sieve[j] = 1;
      }
    }
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}