#include <iostream>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int mna = 1005, ans = 0, negc = 0;
  for (int i = 0; i < 2 * n - 1; i++) {
    int x;
    cin >> x;
    ans += abs(x);
    mna = min(mna, abs(x));
    if (x < 0) {
      negc++;
    }
  }

  if (n % 2 == 0 && negc % 2 == 1) {
    ans -= 2 * mna;
  }

  cout << ans << endl;
}