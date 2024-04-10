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
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) ans++;
    }
    cout << ans << endl;
  }
}