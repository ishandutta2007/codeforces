#include <bits/stdc++.h>
using namespace std;

// 2, 7, 15, ..

int f(int n) {
  int a = 2;
  int b = 5;
  while (a+b <= n) {
    a += b;
    b += 3;
  }
  return n-a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = 0;
    while (n >= 2) {
      ans++;
      n = f(n);
    }
    cout << ans << '\n';
  }
}