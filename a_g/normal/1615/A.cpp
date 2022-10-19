#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s += a;
    }
    cout << (s % n == 0 ? 0 : 1) << '\n';
  }
}