#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int z[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++) {
        if (s[j] == '1') {
          z[(j-i+n)%n]++;
        }
      }
    }
    int tot = accumulate(z, z+n, 0);
    int mx = *max_element(z, z+n);
    cout << (tot+n-2*mx) << '\n';
    fill(z, z+n, 0);
  }
}