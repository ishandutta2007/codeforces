#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int LOG = 20;

int N;
int table[LOG][MAXN];

int main() {
  scanf("%d", &N);
  for (int j = 0; j < N; j++) {
    int x;
    scanf("%d", &x);
    for (int i = 0; i < LOG; i++)
      table[i][j] = x >> i & 1;
  }
  
  for (int i = 0; i < LOG; i++)
    sort(table[i], table[i] + N);
  
  ll ans = 0;
  for (int j = 0; j < N; j++) {
    int tmp = 0;
    for (int i = 0; i < LOG; i++)
      if (table[i][j])
        tmp |= 1 << i;
    ans += (ll)tmp * tmp;
  }
  
  printf("%lld\n", ans);
  
  return 0;
}