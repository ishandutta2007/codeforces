#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool inc = 1;
    for (int i = 0; i < n-1; i++) {
      if (a[i] >= a[i+1]) inc = 0;
    }
    if ((n&1)&inc) {
      cout << "NO" << endl;
    }
    else {
      cout << "YES" << endl;
    }
  }
}