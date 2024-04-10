#include <iostream>

#define int long long

const int MAXN = 505;

int ch[MAXN][MAXN];
int chp[MAXN][MAXN];
int a[MAXN][MAXN];
int ap[MAXN][MAXN];
int b[MAXN][MAXN];
int bp[MAXN][MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int upc = 0;
      if(j)
        upc ^= chp[i][j-1];
      if(i)
        upc ^= chp[i-1][j];
      if(i && j)
        upc ^= chp[i-1][j-1];
      upc ^= 1;
      ch[i][j] = chp[i][j] = upc;
      if(j)
        chp[i][j] ^= chp[i][j-1];
      if(i)
        chp[i][j] ^= chp[i-1][j];
      if(i && j)
        chp[i][j] ^= chp[i-1][j-1];
    }
  }

  for(int i = n-1; i >= 0; i--) {
    for(int j = m-1; j >= 0; j--) {
      char c;
      std::cin >> c;
      a[i][j] = c == 'B';
    }
  }

  int cur = 0;
  int min = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(j)
        a[i][j] ^= ap[i][j-1];
      if(i)
        a[i][j] ^= ap[i-1][j];
      if(i && j)
        a[i][j] ^= ap[i-1][j-1];
      ap[i][j] = a[i][j];
      if(j)
        ap[i][j] ^= ap[i][j-1];
      if(i)
        ap[i][j] ^= ap[i-1][j];
      if(i && j)
        ap[i][j] ^= ap[i-1][j-1];
      cur += a[i][j];
      b[i][j] = 0;
      if(ch[i][j]) {
        b[i][j] = (a[i][j] ? -1 : 1);
      }
      bp[i][j] = b[i][j];
      if(j)
        bp[i][j] += bp[i][j-1];
      if(i)
        bp[i][j] += bp[i-1][j];
      if(i && j)
        bp[i][j] -= bp[i-1][j-1];
    }
  }

  /*
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      std::cout << ch[i][j] << " ";
    }
  std::cout << std::endl;
  }
  */

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int cn = 0;
      if(i+1 < n)
        cn += (a[i+1][0] ? -1 : 1);
      if(j+1 < m)
        cn += (a[0][j+1] ? -1 : 1);
      if(i+1 < n && j+1 < m)
        cn += (a[i+1][j+1] ? -1 : 1);
      min = std::min(min, bp[i][j]+cn);
    }
  }

  int best = cur;
  best = std::min(best, best+min+3);
  std::cout << best << std::endl;

  return 0;
}