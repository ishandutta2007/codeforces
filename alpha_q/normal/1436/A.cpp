#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int x, sum = 0;
    while (n--) {
      scanf("%d", &x); sum += x;
    }
    puts(sum == m ? "YES" : "NO");
  }
  return 0;
}