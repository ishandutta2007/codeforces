#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+m-1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        a[i+j] ^= x;
      }
    }
    cout << (*max_element(a.begin(), a.end()) ? "Ashish" : "Jeel") << '\n';
  }
}