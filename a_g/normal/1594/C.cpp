#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  //cout << T << endl;
  while (T--) {
    int n;
    char c;
    string s;
    cin >> n;
    //cout << n << endl;
    cin >> c;
    //cout << c << endl;
    cin >> s;
    //cout << s << endl;
    set<int> bad;
    for (int i = 0; i < n; i++) {
      if (s[i] != c) bad.insert(i);
    }
    if (bad.size() == 0) {
      cout << 0 << endl;
    }
    else {
      bool onestep = 0;
      int s = 0;
      for (int i = n/2; i < n; i++) {
        if (!bad.count(i)) {
          onestep = 1;
          s = i;
          break;
        }
      }
      if (onestep) {
        cout << 1 << endl;
        cout << s+1 << endl;
      }
      else {
        cout << 2 << endl;
        int nondiv = 2;
        while (n % nondiv == 0) nondiv++;
        cout << n << " " << nondiv << endl;
      }
    }
  }
}