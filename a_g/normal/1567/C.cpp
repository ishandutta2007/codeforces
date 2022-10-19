#include <bits/stdc++.h>
using namespace std;


int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int a = 0;
    int b = 0;
    int i = 0;
    int pow = 1;
    while (n > 0) {
      int q = (n % 100);
      //cout << q << endl;
      b += pow * (q % 10);
      a += pow * (q/10);
      pow *= 10;
      n /= 100;
    }
    //cout << a << " " << b << endl;
    cout << (a+1)*(b+1)-2 << endl;
  }
}