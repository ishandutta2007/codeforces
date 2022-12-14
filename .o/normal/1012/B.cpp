#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using ll = long long;
using llu = unsigned long long;

using namespace std;

const int N_ = 200500;

int N, M, Q;

int par[N_ + N_];

int group(int x) {
  return (par[x] == x) ? x : (par[x] = group(par[x]));
}

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
  scanf("%d%d%d", &N, &M, &Q);
  iota(par, par+N+M+1, 0);

  int ans = N+M-1;

  for(int q = 1; q <= Q; q++) {
    int r, c; scanf("%d%d", &r, &c);
    int a = group(r);
    int b = group(c+N);
    if(a != b) {
      par[a] = b;
      ans -= 1;
    }
  }

  printf("%d\n", ans);

  return 0;
}