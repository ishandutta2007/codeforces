#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAX_N = 1e5 + 5;

ld P [MAX_N];

int main () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> P[i];
  }

  ld ans = 0;
  ld psum = 1;
  ld ksum = 1;
  for (int i = 0; i < n; i++) {
    ans += P[i] * ksum;

    ksum += 2 * psum;
    ksum *= P[i];
    ksum += (1 - P[i]);

    psum *= P[i];
    psum += (1 - P[i]);
  }

  cout << fixed << setprecision(12) << ans << endl;
}