#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 3005;
const int INF = 0x3f3f3f3f;

int N;
int a[MAXN];
int l[MAXN];
ll dp[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

ll f(int val, int x) {
  return x ? abs(a[x] - val) + (val - 1 < l[x - 1] ? f(val - 1, x - 1) : dp[x - 1]) : 0;
}

int left(int x) {
  int lo = -INF, hi = INF;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (f(mid, x) > f(mid + 1, x)) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}

ll solve() {
  for (int i = 1; i <= N; i++) {
    l[i] = left(i);
    dp[i] = f(l[i], i);
  }
  return dp[N];
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}