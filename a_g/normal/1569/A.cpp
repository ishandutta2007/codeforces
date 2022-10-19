#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool done = 0;
    for (int i = 0; i < n-1; i++) {
      if (s[i] != s[i+1]) {
        cout << i+1 << " " << i+2 << endl;
        done = 1;
        break;
      }
    }
    if (!done) cout << "-1 -1" << endl;
  }
}