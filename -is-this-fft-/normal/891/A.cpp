#include <iostream>

using namespace std;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

const int MAX_N = 2e3 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int gc = 0, c1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    gc = gcd(gc, arr[i]);
    c1 += (int) (arr[i] == 1);
  }

  if (gc != 1) {
    cout << -1 << endl;
    return 0;
  }

  if (c1 != 0) {
    cout << n - c1 << endl;
    return 0;
  }

  int ans = 3 * n;
  for (int i = 0; i < n; i++) {
    int gc = 0;
    for (int j = i; j < n; j++) {
      gc = gcd(gc, arr[j]);
      if (gc == 1) {
        ans = min(ans, n - 1 + j - i);
        break;
      }
    }
  }
  cout << ans << endl;
}