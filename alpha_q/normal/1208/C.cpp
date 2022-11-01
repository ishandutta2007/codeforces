#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, a[N][N], ptr;

int main() {
  cin >> n;
  for (int i = 0; i < n; i += 4) {
    for (int j = 0; j < n; j += 4) {
      for (int k = i; k < i + 4; ++k) {
        for (int l = j; l < j + 4; ++l) {
          a[k][l] = ptr++;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) printf("%d ", a[i][j]);
    puts("");
  }
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < n; ++j) sum ^= a[i][j];
    assert(sum == 0);
    sum = 0;
    for (int j = 0; j < n; ++j) sum ^= a[j][i];
    assert(sum == 0);
  }
  return 0;
}