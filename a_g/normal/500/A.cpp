#include <bits/stdc++.h>
using namespace std;

const int N = 3e4+5;
int a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, t;
  cin >> n >> t;
  for (int i = 1; i <= n-1; i++) cin >> a[i];
  int cur = 1;
  while (cur < n) {
    cur += a[cur];
    if (cur == t) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}