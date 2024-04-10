#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(1, 1);
    long long s = 1;
    while (s < n) {
      s += 2*a.back();
      a.push_back(2*a.back());
    }
    for (int i = (int)a.size()-1; i >= 1; i--) {
      int d = min<int>(a[i]/2, s-n);
      a[i] -= d;
      s -= d;
      if (!s) break;
    }
    cout << (int)a.size()-1 << '\n';
    for (int i = 0; i < (int)a.size()-1; i++) {
      cout << a[i+1]-a[i] << ' ';
    }
    cout << '\n';
  }
}