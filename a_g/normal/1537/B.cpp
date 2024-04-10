#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    int cornerx, cornery;
    if (i > n/2) cornerx = 1;
    else cornerx = n;

    if (j > m/2) cornery = 1;
    else cornery = m;
    cout << cornerx << " " << cornery << " " << n+1-cornerx << " " << m+1-cornery << endl;
  }
}