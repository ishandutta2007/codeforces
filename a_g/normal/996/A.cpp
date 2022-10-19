#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int u: {100, 20, 10, 5, 1}) {
    ans += n/u;
    n %= u;
  }
  cout << ans << endl;
}