#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  if (n > m) {
    cout << 0 << endl;
    return 0;
  }
  
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  long long prod = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      prod *= abs(arr[i] - arr[j]);
      prod %= m;
    }
  }

  cout << prod << endl;
}