#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, a;
    cin >> n;
    ll sum=0;
    ll xorsum=0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      sum += a;
      xorsum ^= a;
    }
    ll seed = 8*sum + (sum % 2);
    cout << 3 << endl;
    cout << seed << " ";
    ll v = (2*(seed^xorsum)-(sum+seed))/2;
    cout << v << " " << v << endl;
  }
}