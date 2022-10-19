#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  bool free = 0;
  int neg = 0;
  long long ans = 0;
  int n, val;
  cin >> n;
  while (n--) {
    cin >> val;
    if (val < 0) neg++;
    if (val == 0) free =1;
    ans += abs(abs(val)-1);
  }
  if (!free && (neg & 1)) ans +=2;
  cout << ans << endl;
}