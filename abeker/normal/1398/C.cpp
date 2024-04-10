#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
char s[MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d%s", &N, s + 1);
    map <int, int> cnt = {{0, 1}};
    int sum = 0;
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
      sum += s[i] - '0';
      ans += cnt[sum - i]++;
    }
    printf("%lld\n", ans);
  }
  return 0;
}