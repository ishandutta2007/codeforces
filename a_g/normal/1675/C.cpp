#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    int l = 0;
    int r = n-1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') l = i;
    }
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == '0') r = i;
    }
    cout << r-l+1 << '\n';
  }
}