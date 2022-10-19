#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (m == 1) {
    cout << n-1 << '\n';
  }
  else {
    cout << 1LL*(m-1)*n << '\n';
  }
}