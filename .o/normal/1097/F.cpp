#include <bits/stdc++.h>

using namespace std;

using lint = long long;

const int C = 7000;
const int N_ = int(1.1e5);
const int C_ = C + 3;

#define div divdivdivdiv

bitset<C_> div[C_], chk[C_], S[N_];
bool isp[C_];

bool mu[C_];

int N, Q;

int main() {
  for(int i = 1; i <= C; i++) {
    mu[i] = 1;
    for(int j = 1; j <= i; j++) {
      if(i % j == 0) {
        div[i][j] = 1;
        if(isp[j] && (i / j) % j == 0) mu[i] = 0;
        if(j > 1 && mu[i / j]) chk[j][i] = 1; 
      }
    }
    if(mu[i]) chk[1][i] = 1;
    isp[i] = div[i].count() == 2;
  }

#ifdef IN_MY_COMPUTER
  freopen("f.in", "r", stdin);
#endif
  scanf("%d%d", &N, &Q);

  while(Q--) {
    int t; scanf("%d", &t);
    if(t == 1) {
      int x, v; scanf("%d%d", &x, &v);
      S[x] = div[v];
    }else if(t == 2) {
      int x, y, z; scanf("%d%d%d", &x, &y, &z);
      S[x] = S[y] ^ S[z];
    }else if(t == 3) {
      int x, y, z; scanf("%d%d%d", &x, &y, &z);
      S[x] = S[y] & S[z];
    }else if(t == 4) {
      int x, v; scanf("%d%d", &x, &v);
      printf("%lu", (S[x] & chk[v]).count() % 2);
    }
  }
  
  return 0;
}