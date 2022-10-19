#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    cout << min({a, b, (a+b)/4}) << '\n';
  }
}