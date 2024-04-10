#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int a;
    string ans = "NO";
    for (int i = 0; i < k1; i++) {
      cin >> a;
      if (a == n) ans = "YES";
    }
    cout << ans << endl;
    for (int i = 0; i < k2; i++) {
      cin >> a;
    }
  }
}