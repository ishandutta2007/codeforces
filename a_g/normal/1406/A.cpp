#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int x = 0;
    int y = 0;
    while (count(a.begin(), a.end(), y) >= 2) {
      x++;
      y++;
    }
    while (count(a.begin(), a.end(), x) >= 1) {
      x++;
    }
    cout << x+y << '\n';
  }
}