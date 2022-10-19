#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    bool good = 0;
    if ((a+b+c)%2 == 0) {
      good = (a == b || b == c || c == a || a == b+c || b == c+a || c == a+b);
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}