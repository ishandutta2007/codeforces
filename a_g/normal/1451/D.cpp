#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int d, k;
    cin >> d >> k;
    int x = 0;
    while (2LL*(x+k)*(x+k) <= 1LL*d*d) x += k;
    cout << (1LL*x*x+1LL*(x+k)*(x+k) > 1LL*d*d ? "Utkarsh" : "Ashish") << '\n';
  }
}