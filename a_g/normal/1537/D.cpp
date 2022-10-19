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
    if (n & 1) cout << "Bob" << endl;
    else {
      if ((n & (n-1)) != 0) {
        cout << "Alice" << endl;
      }
      else {
        int pow = 0;
        while ((1 << pow) < n) pow++;
        if (pow & 1) cout << "Bob" << endl;
        else cout << "Alice" << endl;
      }
    }
  }
}