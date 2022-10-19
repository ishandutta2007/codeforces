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
    for (int i = 0; i < n; i++) cin >> a[i];
    bool die = 0;
    int h = 1;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        if (a[i] == 1) h++;
      }
      else {
        if (a[i] == 0 && a[i-1] == 0) die = 1;
        if (a[i] == 1 && a[i-1] == 1) h += 5;
        if (a[i] == 1 && a[i-1] == 0) h++;
      }
    }
    cout << (die ? -1 : h) << endl;
  }
}