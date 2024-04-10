#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n&1) {
      for (int i = 1; i <= (n-3)/2; i++) {
        cout << 2*i << " " << 2*i-1 << " ";
      }
      cout << n << " " << n-2 << " " << n-1 << endl;
    }
    else {
      for (int i = 1; i <= n/2; i++) {
        cout << 2*i << " " << 2*i-1 << " ";
      }
      cout << endl;
    }
  }
}