#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  long long sx = 0, sy = 0;
  for (int i = 0; i < 2*n; i++) {
    int x, y;
    cin >> x >> y;
    sx += x;
    sy += y;
  }
  cout << sx/n << " " << sy/n << '\n';
}