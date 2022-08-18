#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  int oc = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    oc += arr[i];
  }

  for (int i = 0; i < qc; i++) {
    int t, x;
    cin >> t >> x;

    if (t == 1) {
      oc -= arr[x];
      arr[x] = !arr[x];
      oc += arr[x];
    } else {
      if (oc >= x) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
  }
}