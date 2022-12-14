#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using ll = long long;
using llu = unsigned long long;

using namespace std;

const int N_ = 100500;

int N;
ll A[N_ * 2];

ll ans = 1e18;

int main() {
#ifdef IN_MY_COMPUTER
  {
    char tmp[100];
    sprintf(tmp, "%s", __FILE__);
    int len = (int)strlen(tmp);
    while(tmp[len-1] != '.') tmp[--len] = 0;
    sprintf(tmp + strlen(tmp), "in");
    freopen(tmp, "r", stdin);
  }
#endif
  scanf("%d", &N);
  for(int i = 0; i < N*2; i++) {
    scanf("%lld", &A[i]);
  }
  sort(A, A+N*2);

  for(int i = 0; i <= N; i++) {
    long long w = A[i+N-1] - A[i];
    long long h = (i == N ? A[N-1] : A[N+N-1]) - (i == 0 ? A[N] : A[0]);
    ans = min(ans, w*h);
  }

  printf("%lld\n", ans);
  return 0;
}