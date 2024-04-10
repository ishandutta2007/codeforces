#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) 
    cin >> arr[i];
  int best_ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    int cur2 = 0;
    while (cur + arr[(i + cur2) % n] <= 180) {
      cur += arr[(i + cur2) % n];
      cur2++;
    }
    best_ans = min(best_ans, 2 * (180 - cur));
  }
  cout << best_ans << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}