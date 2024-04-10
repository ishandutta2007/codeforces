#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int zerocount = 0;
    int onecount = 0;
    bool valid = true;
    for (int i = 0; i < k; i++) {
      bool iszero = false;
      bool isone = false;
      int j = 0;
      while (k*j+i < n) {
        int index = k*j+i;
        if (s[index] == '0') {
          if (isone) valid = false;
          iszero = true;
        }
        else if (s[index] == '1') {
          if (iszero) valid = false;
          isone = true;
        }
        j++;
      }
      if (iszero) zerocount++;
      if (isone) onecount++;
    }
    if (!valid || zerocount > k/2 || onecount > k/2) {
      cout << "NO" << '\n';
    }
    else {
      cout << "YES" << '\n';
    }
  }
}