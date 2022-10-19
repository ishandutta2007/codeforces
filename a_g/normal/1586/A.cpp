#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool composite (int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return 1;
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (composite(sum)) {
      cout << n << endl;
      for (int i = 0; i < n; i++) {
        cout << i+1 << " ";
      }
      cout << endl;
    }
    else {

      int exclude;
      for (int i = 0; i < n; i++) {
        if (composite(sum-a[i])) {
          exclude = i;
        }
      }
      cout << n-1 << endl;
      for (int i = 0; i < n; i++) {
        if (i != exclude) cout << i+1 << " ";
      }
      cout << endl;
    }
  }
}