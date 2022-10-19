#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int s = 0;
    while (n--) {
      int a;
      cin >> a;
      s += a;
    }
    cout << (s == m ? "YES" : "NO") << '\n';
  }
}