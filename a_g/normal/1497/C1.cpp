#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if ((n & 1)^(k & 1)) {
      if ((n-k) % 4 == 3 || k > n/2 + 1) {
        cout << 2 << " ";
        for (int i = 0; i < k-3; i++) {
          cout << 1 << " ";
        }
        cout << (n-k+1)/2 << " " << (n-k+1)/2 << endl;
      }
      else if (k >= 5){
        cout << "2 2 2 ";
        for (int i = 0; i < k-5; i++) {
          cout << 1 << " ";
        }
        cout << (n-k-1)/2 << " " << (n-k-1)/2 << endl;
      }
      else {
        for (int i = 0; i < k-3; i++) {
          cout << 1 << " ";
        }
        int m = n-(k-3);
        cout << m/4 << " " << m/4 << " " << m/2 << endl;
      }
    }
    else {
      for (int i = 0; i < k-2; i++) {
        cout << 1 << " ";
      }
      cout << (n-k+2)/2 << " " << (n-k+2)/2 << endl;
    }
  }
}