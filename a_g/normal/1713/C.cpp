#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  if (n < 0) return;
  int k = floor(sqrt(n));
  if (k*k < n) k++;
  assert(k*k >= n);
  solve(k*k-n-1);
  for (int i = n; i >= k*k-n; i--) {
    cout << i << ' ';
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    solve(n-1);
    cout << '\n';
  }
}