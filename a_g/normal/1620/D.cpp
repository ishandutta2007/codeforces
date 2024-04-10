#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> residues(3);
    int M = 0;
    bool hasone = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      residues[a[i] % 3] = 1;
      M = max(M, a[i]);
      if (a[i] == 1) hasone = 1;
    }
    bool hasx = count(a.begin(), a.end(), M-1);
    int ans = (M+2)/3;
    if (M % 3 == 0) {
      if (residues[1] || residues[2]) ans++;
    }
    else if (M % 3 == 1) {
      if (residues[2] && (hasx || hasone)) ans++;
    }
    else {
      if (residues[1]) ans++;
    }
    cout << ans << '\n';
  }
}