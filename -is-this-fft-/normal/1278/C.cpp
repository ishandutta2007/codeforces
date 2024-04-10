#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];
int preb [MAX_N];
int sufb [MAX_N];

int _first_w [2 * MAX_N];
int& first_w (int x) {
  return _first_w[x + MAX_N];
}

void solve () {
  int N;
  cin >> N;

  for (int i = 0; i < 2 * N; i++) {
    cin >> arr[i];
    if (arr[i] == 2) arr[i] = -1;
  }

  preb[0] = arr[0];
  for (int i = 1; i < 2 * N; i++) {
    preb[i] = preb[i - 1] + arr[i];
  }

  sufb[2 * N - 1] = arr[2 * N - 1];
  for (int i = 2 * N - 2; i >= 0; i--) {
    sufb[i] = sufb[i + 1] + arr[i];
  }
  
  for (int i = -2 * N; i <= 2 * N; i++) {
    first_w(i) = 1 << 30;
  }

  for (int i = N; i < 2 * N; i++) {
    first_w(sufb[i]) = min(first_w(sufb[i]), i);
  }
  first_w(0) = min(first_w(0), 2 * N);
  
  int ans = first_w(0);
  for (int i = 0; i < N; i++) {
    ans = min(ans, first_w(-preb[i]) - i - 1);
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}