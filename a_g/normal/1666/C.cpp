#include <bits/stdc++.h>
using namespace std;

long long x[3], y[3];
long long ax[5], ay[5];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

  int midx = x[0] + x[1] + x[2] - *min_element(x, x+3) - *max_element(x, x+3);
  int midy = y[0] + y[1] + y[2] - *min_element(y, y+3) - *max_element(y, y+3);
  cout << "6\n";
  for (int i = 0; i < 3; i++) {
    cout << midx << " " << midy << " " << x[i] << " " << midy << '\n';
    cout << x[i] << " " << midy << " " << x[i] << " " << y[i] << '\n';
  }
}