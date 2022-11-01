#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, b[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
  }
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    int cur = b[i] + mx;
    printf("%d ", cur);
    mx = max(mx, cur);
  }
  cout << '\n';
  return 0;
}