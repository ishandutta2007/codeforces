#include <iostream>

#define int long long

const int MAXK = 21;
const int MAXN = 100005;
const int MOD = 1000000007;
int powe[MAXK][MAXN];

signed main() {

  for(int i = 1; i < MAXK; i++)
    powe[i][0] = 1;

  for(int i = 1; i < MAXK; i++)
    for(int j = 1; j < MAXN; j++)
      powe[i][j] = (powe[i][j-1]*i)%MOD;

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;
    int ans = 1;
    for(int i = 0; i < k; i++)
      ans = (ans*n)%MOD;
    std::cout << ans << std::endl;
  }

  return 0;
}