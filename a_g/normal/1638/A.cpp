#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int target = 1;
    for (int i = 0; i < n; i++) {
      if (p[i] != i+1) {
        target = i+1;
        break;
      }
    }
    reverse(p.begin()+target-1, find(p.begin(), p.end(), target)+1);
    for (int x: p) cout << x << ' ';
    cout << '\n';
  }
}