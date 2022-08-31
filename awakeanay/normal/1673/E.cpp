#include <iostream>
#include <vector>

#define int long long

const int LEN = 24;
const int MAXN = (1 << 20);

int fact[MAXN];
int choose[LEN][MAXN];

int binom(int n, int k) {
  if(n < k || k < 0 || n < 0)
    return 0;
  return (fact[n] - fact[k] - fact[n-k] == 0);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fact[0] = 0;
  for(int i = 1; i < MAXN; i++) {
    int cur = i;
    while(cur%2 == 0) {
      cur /= 2;
      fact[i]++;
    }
    fact[i] += fact[i-1];
  }

  int n, k;
  std::cin >> n >> k;

  for(int i = 0; i < LEN && i < n; i++) {
    for(int j = 0; j < MAXN; j++) {
      choose[i][j] = binom(n-1-i, j);
    }
    for(int j = MAXN-2; j >= 0; j--) {
      choose[i][j] += choose[i][j+1];
    }
  }

  int b[n];
  for(int i = 0; i < n; i++)
    std::cin >> b[i];

  std::vector<int> ans(MAXN, 0);
  for(int i = 0; i < n; i++) {
    int cur = b[i];
    for(int j = i; j < n; j++) {
      if(j > i && b[j] > 20)
        break;
      if(j > i)
        cur *= 1 << b[j];
      if(cur >= MAXN)
        break;
      int tot = n-1-(j-i+(i > 0)+(j+1 < n));
      int need = k-(i > 0)-(j+1 < n);
      need = std::max(0ll, need);
      ans[cur] ^= choose[n-1-tot][need]&1;
    }
  }

  int j = (1 << 20)-1;
  while(j > 0 && ans[j] == 0)
    j--;
  for(int i = j; i >= 0; i--)
    std::cout << ans[i];

  return 0;
}