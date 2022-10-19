#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << max(max(x, a-1-x)*b, max(y, b-1-y)*a) << endl;
  }
}