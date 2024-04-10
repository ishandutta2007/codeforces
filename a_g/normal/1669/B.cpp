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
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x-1]++;
    }
    auto it = max_element(a.begin(), a.end());
    cout << (*it >= 3 ? it-a.begin()+1 : -1) << '\n';
  }
}