#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(12);
  int n, r;
  cin >> n >> r;
  vector<int> x(n);
  for (int& l: x) cin >> l;
  vector<double> h(n);
  for (int i = 0; i < n; i++) {
    h[i] = r;
    for (int j = 0; j < i; j++) {
      if (abs(x[j]-x[i]) <= 2*r) {
        h[i] = max(h[i], h[j]+sqrt(4*r*r-abs(x[j]-x[i])*abs(x[j]-x[i])));
      }
    }
    cout << h[i] << " \n"[i+1==n];
  }

}