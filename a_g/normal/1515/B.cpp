#include <bits/stdc++.h>
using namespace std;

bool is_square(int x) {
  int low = 0;
  int high = 4e4;
  while (high-low > 1) {
    int mid = (low+high)/2;
    if (mid*mid <= x) low = mid;
    else high = mid;
  }
  return low*low == x;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << (n%2 == 0 && (is_square(n) || is_square(n/2)) ? "YES" : "NO") << '\n';
  }
}