#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using ll = long long;
using llu = unsigned long long;

using namespace std;

const int N_ = 5050;

int N;
int A[N_];

long long tb[N_][N_][2];

int cost(int from, int to) {
  // from to  ?
  return (from >= to) ? (from - to + 1) : 0;
}

void upd (ll &val, ll n){ 
  if(val > n) val = n;
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

  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }
  
  fill((ll*)tb, (ll*)tb+N_*N_*2, ll(1e18));
  for(int i = 0; i <= N; i++) {
    tb[i][0][0] = 0;
  }

  for(int i = 0; i <= N; i++) {
    for(int k = 0; 2*k-1 <= N; k++) {
      upd(tb[i+1][k][0], tb[i][k][0]);
      upd(tb[i+1][k][0], tb[i][k][1]);
      upd(tb[i+1][k+1][1], tb[i][k][0] + cost(A[i], A[i+1]) + cost(A[i+2], A[i+1]));
      upd(tb[i+2][k+1][1], tb[i][k][1] + cost(min(A[i]-1, A[i+1]), A[i+2]) + cost(A[i+3], A[i+2]));
    }
  }

  for(int k = 1; 2*k-1 <= N; k++) {
    printf("%lld ", min(tb[N][k][0], tb[N][k][1]));
  }

  return 0;
}