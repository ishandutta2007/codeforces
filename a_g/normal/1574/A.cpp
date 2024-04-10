#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = n; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        cout << "(";
      }
      for (int j = 0; j < i; j++) {
        cout << ")";
      }
      for (int j = 0; j < n-i; j++){
        cout << "()";
      }
      cout << endl;
    }
  }
}