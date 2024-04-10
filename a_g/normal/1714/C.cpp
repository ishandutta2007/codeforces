#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;
    vector<int> a;
    int s = 0;
    for (int i = 9; i >= 1; i--) {
      if (s+i <= x) {
        s += i;
        a.push_back(i);
      }
    }
    reverse(a.begin(), a.end());
    for (int x: a) {
      cout << x;
    }
    cout << '\n';
  }
}