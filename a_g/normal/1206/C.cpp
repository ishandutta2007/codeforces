#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  if (n & 1) {
    int m = 2*n;
    cout << "YES\n";
    vector<int> vals(m);
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        vals[i] = 2*i+1;
        vals[i+n] = 2*i+2;
      }
      else {
        vals[i] = 2*i+2;
        vals[i+n] = 2*i+1;
      }
    }
    for (int k: vals) {
      cout << k << " ";
    }
    cout << "\n";
    return 0;
  }
  cout << "NO\n";
}