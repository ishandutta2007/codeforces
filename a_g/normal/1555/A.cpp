#include <bits/stdc++.h>
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    /*if (14 <= n && n < 16) {
      n = 16;
    }*/
    cout << max<long long>(15, 5*((n+1)/2)) << endl;
  }
}