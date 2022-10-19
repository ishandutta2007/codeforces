#include <bits/stdc++.h>
using namespace std;

int query(int x, int l, int r) {
  cout << "? " << 1 << " " << r-l+1 << '\n';
  cout << x << '\n';
  for (int i = l; i <= r; i++) {
    cout << i << ' ';
  }
  cout << endl;
  int k;
  cin >> k;
  return k;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<bool> demag(n+1, 1);
    demag[0] = 0;
    for (int i = 2; i <= n; i++) {
      if (query(i, 1, i-1)) {
        // i is the second magnet that's nonzero
        demag[i] = 0;
        int low = 0;
        int high = i-1;
        while (high-low > 1) {
          int mid = (low+high)/2;
          if (query(i, 1, mid)) high = mid;
          else low = mid;
        }
        demag[high] = 0;

        for (int j = i+1; j <= n; j++) {
          demag[j] = (query(i, j, j) == 0);
        }
        cout << "! " << accumulate(demag.begin(), demag.end(), 0);
        for (int i = 1; i <= n; i++) {
          if (demag[i]) cout << ' ' << i;
        }
        cout << endl;
        break;
      }
    }
  }
}