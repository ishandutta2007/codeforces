#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int minsofar = 0;
    map<int, int> valtoindex;
    for (int i = 0; i < n; i++) {
      if (b[i] > minsofar) {
        for (int j = minsofar+1; j < b[i]; j += 2) {
          valtoindex[j] = i;
        }
        minsofar = b[i];
      }
    }
    int ans = 9999999;
    for (int i = 0; i < n; i++) {
      if (i > ans) break;
      ans = min(ans, i+valtoindex[a[i]]);
    }
    cout << ans << endl;
  }
}