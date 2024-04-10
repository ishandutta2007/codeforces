#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, s;
    cin >> n >> s;
    cout << (s)/((n+2)/2) << endl;
  }
}