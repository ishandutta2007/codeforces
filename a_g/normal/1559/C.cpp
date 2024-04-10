#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> roads(n);
    for (int i = 0; i < n; i++) cin >> roads[i];
    if (roads[n-1] == 0) {
      for (int i = 1; i <= n+1; i++) {
        cout << i << " ";
      }
      cout << endl;
    }
    else if (roads[0] == 1) {
      cout << n+1 << " ";
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
    }
    else {
      for (int i = 0; i < n; i++) {
        if (roads[i] == 0 && roads[i+1] == 1) {
          for (int j = 1; j <= i+1; j++) {
            cout << j << " ";
          }
          cout << n+1 << " ";
          for (int j = i+2; j <= n; j++) {
            cout << j << " ";
          }
          cout << endl;
          break;
        }
      }
    }
  }
}