#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "a" << endl;
    }
    else if (n == 2) {
      cout << "ab" << endl;
    }
    else if (n & 1) {
      cout << string(n/2-1, 'a') << 'b' << string(n/2, 'a') << 'c' << endl;
    }
    else {
      cout << string(n/2-1, 'a') << 'b' << string(n/2, 'a') << endl;
    }
  }
}