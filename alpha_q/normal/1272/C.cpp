#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

char s[N];
int n, k, good[69], a[N];

int main() {
  cin >> n >> k;
  scanf("%s", s + 1);
  for (int i = 1; i <= k; ++i) {
    char ch[2]; scanf("%s", ch);
    good[ch[0] - 'a'] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = good[s[i] - 'a'];
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!a[i]) continue;
    int j = i, len = 0;
    while (j <= n and a[j]) ++j, ++len;
    ans += (ll) len * (len + 1) / 2, i = j;
  }
  cout << ans << '\n';
  return 0;
}