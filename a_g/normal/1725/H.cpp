#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int c[2] = {0, 0};
  for (int& x: a) {
    cin >> x;
    c[x%3 != 0]++;
  }
  int k = (c[0] > c[1] ? 0 : 1);
  cout << (k ? 0 : 2) << '\n';
  int cnt = n/2;
  for (int i = 0; i < n; i++) {
    if (cnt && ((a[i]%3 == 0)^k)) {
      cout << '0';
      cnt--;
    }
    else {
      cout << '1';
    }
  }
  cout << '\n';
}