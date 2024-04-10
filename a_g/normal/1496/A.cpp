#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool valid = true;
    for (int i = 0; i < k; i++) {
      if (s[i] != s[n-1-i]) valid = false;
    }
    if (n == 2*k) valid = false;
    cout << (valid ? "YES" : "NO") << endl;
  }
}