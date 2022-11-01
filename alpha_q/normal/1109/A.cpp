#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 20) + 5;

long long ans;
int n, a[N], cnt[N][2];

int main() {
  cin >> n;
  ++cnt[0][0];
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    a[i] ^= a[i - 1];
    ans += (long long) cnt[a[i]][i & 1];
    ++cnt[a[i]][i & 1];
  }
  cout << ans << '\n';
  return 0;
}