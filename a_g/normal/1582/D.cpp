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
    for (int i = 0; i < n/2-1; i++) {
      cout << a[2*i+1] << " " << -a[2*i] << " ";
    }
    if (n & 1) {
      int x = a[n-3];
      int y = a[n-2];
      int z = a[n-1];
      int signx = (x > 0 ? 1 : -1);
      int signy = (y > 0 ? 1 : -1);
      int signz = (z > 0 ? 1 : -1);
      if (abs(x) == abs(y)) {
        if (abs(z) == 1) {
          cout << -signx << " " << (abs(z)+1)*signy << " " << -signz*abs(x);
        }
        else {
          cout << signx << " " << (abs(z)-1)*signy << " " << -signz*abs(x);
        }
      }
      else if (abs(y) == abs(z)) {
        if (abs(x) == 1) {
          cout << -abs(y)*signx << " " << (abs(x)+1)*signy << " " << -signz;
        }
        else {
          cout << -abs(y)*signx << " " << (abs(x)-1)*signy << " " << signz;
        }
      }
      else if (abs(x) == abs(z)) {
        if (abs(y) == 1) {
          cout << (abs(y)+1)*signx << " " << -abs(x)*signy << " " << -signz;
        }
        else {
          cout << (abs(y)-1)*signx << " " << -abs(x)*signy << " " << signz;
        }
      }
      else {
        cout << signx*(abs(y)-abs(z)) << " " << signy*(abs(z)-abs(x)) << " " <<
          signz*(abs(x)-abs(y));
      }
      cout << endl;
    }
    else {
      cout << a[n-1] << " " << -a[n-2] << endl;
    }
  }
}