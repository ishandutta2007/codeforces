#include <bits/stdc++.h>

using namespace std;

int t;
long long n, k;

int main() {
  cin >> t;
  while (t--) {
    scanf("%lld %lld", &n, &k);
    if ((n & 1) != (k & 1)) {
      puts("NO");
      continue; 
    }
    if (n < k * k) {
      puts("NO");
      continue;
    }
    puts("YES");
  }
  return 0;
}