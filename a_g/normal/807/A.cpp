#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a != b) {
      cout << "rated" << endl;
      return 0;
    }
    p[i] = a;
  }
  for (int i = 0; i < n-1; i++) {
    if (p[i] < p[i+1]) {
      cout << "unrated" << endl;
      return 0;
    }
  }
  cout << "maybe" << endl;
}