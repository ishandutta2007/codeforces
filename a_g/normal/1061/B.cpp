#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  long long s = 0;
  vector<int> a(n);
  for (int& x: a) cin >> x, s += x;
  sort(a.begin(), a.end());
  int h = 0;
  int d = 0;
  for (int x: a) {
    if (x) {
      d++;
      if (h < x) h++;
    }
  }
  d += a[n-1]-h;
  cout << s-d << '\n';
}