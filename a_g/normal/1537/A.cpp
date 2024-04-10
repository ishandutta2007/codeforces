#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      sum += val;
    }
    if (sum < n) {
      cout << 1 << endl;
    }
    else if (sum == n) {
      cout << 0 << endl;
    }
    else {
      cout << sum-n << endl;
    }
  }
}