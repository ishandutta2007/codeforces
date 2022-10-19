#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<bool> valid(n, 1);
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      valid[b-1] = 0;
    }
    int center;
    for (int i = 0; i < n; i++) {
      if (valid[i]) {center = i+1; break;}
    }
    for (int i = 1; i <= n; i++) {
      if (i != center) {
        cout << center << " " << i << '\n';
      }
    }
  }
}