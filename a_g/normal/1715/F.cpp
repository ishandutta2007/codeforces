#include <bits/stdc++.h>
using namespace std;


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(15);
  int n, m;
  cin >> n >> m;
  cout << "? " << 2*n+2 << '\n';
  for (int i = 0; i < n; i++) {
    cout << i << " 0\n";
    cout << i+1 << ' ' << m << '\n';
  }
  cout << n << ' ' << m+1 << '\n';
  cout << 0 << ' ' << m+1 << endl;
  double y;
  cin >> y;
  y = m*y-0.5;

  cout << "? " << 2*m+2 << '\n';
  for (int i = 0; i < m; i++) {
    cout << 0 << ' ' << i << '\n';
    cout << n << ' ' << i+1 << '\n';
  }
  cout << n+1 << ' ' << m << '\n';
  cout << n+1 << ' ' << 0 << endl;
  double x;
  cin >> x;
  x = n*x-0.5;

  cout << "! " << x << ' ' << y << endl;
}