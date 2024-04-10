#include <bits/stdc++.h>
using namespace std;
int counts[4];

int main () {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    counts[2*(x/2 % 2) + (y/2 % 2)]++;
  }
  long long ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += (1LL*counts[i]*(counts[i]-1)*(counts[i]-2))/6;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      ans += (1LL*counts[i]*counts[j]*(counts[j]-1))/2;
    }
  }
  cout << ans << '\n';
}