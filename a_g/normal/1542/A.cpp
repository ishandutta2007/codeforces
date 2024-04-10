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
    int count = 0;
    for (int i = 0; i < 2*n; i++) {
      int a;
      cin >> a;
      count += a&1;
    }
    cout << (n==count ? "Yes" : "No") << endl;
  }
}