#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; scanf("%d", &n);
  vector<int> v(n);
  for(int &x : v) scanf("%d", &x);

  for(int mask = 0; mask < (1<<n); mask++) {
    int s = 0;
    for(int i = 0; i < n; i++) {
      s += (mask >> i) & 1 ? +v[i] : -v[i];
    }
    if(s % 360 == 0) {
      puts("YES");
      return 0;
    }
  }

  puts("NO");
  return 0;
}