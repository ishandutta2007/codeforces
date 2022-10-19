#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int i = 0;
    bool waiting = false;
    int waitingval;
    int ans = 0;
    while (i < n) {
      if (waiting && waitingval == 0) {
        if (a[i] == '1' && b[i] == '1') {
          ans += 2;
          waiting = false;
        }
        else if (a[i] == '0' && b[i] == '0') { 
          ans++;
        }
        else {
          ans += 3;
          waiting = false;
        }
      }

      else if (waiting && waitingval == 1) {
        if (a[i] == '0' && b[i] == '0') { 
          ans += 2;
          waiting = false;
        }
        else if (a[i] == '0' || b[i] == '0') { 
          ans += 2;
          waiting = false;
        }
      }
      else {
        if (a[i] == '0' && b[i] == '0') {
          waiting = true;
          waitingval = 0;
        }
        else if (a[i] == '1' && b[i] == '1') {
          waiting = true;
          waitingval = 1;
        }
        else {
          ans += 2;
        }
      }
      i++;
    }
    if (waiting && waitingval == 0) {
      ans++;
    }
    cout << ans << endl;
  }
}