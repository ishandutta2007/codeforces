#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> sights(n*m);
    for (int i = 0; i < n*m; i++) {
      cin >> sights[i];
    }
    int ans = 0;
    for (int i = 0; i < n*m; i++) {
      for (int j = i+1; j < n*m; j++) {
        if (sights[i] < sights[j]) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}