#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    bool win = 0;
    if (2*b-a > 0 && (2*b-a)%c == 0) win = 1;
    if (2*b-c > 0 && (2*b-c)%a == 0) win = 1;
    if ((a+c)%2 == 0 && ((a+c)/2)%b == 0) win = 1;
    cout << (win ? "YES" : "NO") << '\n';
  }
}