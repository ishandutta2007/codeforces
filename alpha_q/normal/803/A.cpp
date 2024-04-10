#include <bits/stdc++.h> 

using namespace std;

int a[105][105], n, k;

int main (int argc, char const *argv[]) {
  cin >> n >> k;
  for (int i = 1; k and i <= n; ++i) {
    for (int j = i; k and j <= n; ++j) {
      if (i == j) {
        --k;
        a[i][i] = 1;
      } else {
        if (k > 1) {
          a[i][j] = a[j][i] = 1;
          k -= 2;
        }
      }
    }
  }
  if (k) puts("-1");
  else {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        printf("%d ", a[i][j]);
      }
      puts("");
    }
  }
  return 0;
}