#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  cout << 4+3*n << '\n';
  cout << "0 0\n";
  for (int i = 0; i <= n; i++) {
    cout << i+1 << " " << i << '\n';
    cout << i << " " << i+1 << '\n';
    cout << i+1 << " " << i+1 << '\n';
  }
}