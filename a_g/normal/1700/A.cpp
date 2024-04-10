#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    cout << 1LL*m*(m-1)/2 + 1LL*m*n*(n+1)/2 << '\n';
  }
}