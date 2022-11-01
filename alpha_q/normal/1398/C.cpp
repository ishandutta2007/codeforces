#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n;
char s[N];
map <int, int> f;

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %s", &n, s + 1);
    int sum = 0;
    f.clear(), ++f[0];
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      int x = s[i] - '0';
      sum += x, ans += f[sum - i], ++f[sum - i];
    }
    cout << ans << '\n';
  }
  return 0;
}