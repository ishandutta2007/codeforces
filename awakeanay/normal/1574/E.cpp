#include <iostream>
#include <map>
#include <vector>

#define int long long

const int MAXN = 1000006;
const int MOD = 998244353;

int p2[MAXN];

int wrong(int x, int y) {
  return (x != 0 && y != 0);
}

int fixed(int x, int y) {
  return (x == 0 && y != 0) || (x != 0 && y == 0);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  p2[0] = 1;
  for(int i = 1; i < MAXN; i++)
    p2[i] = (p2[i-1]*2)%MOD;

  int n, m, k;
  std::cin >> n >> m >> k;

  int type[2];
  type[0] = type[1] = 0;

  std::vector<int> row[2];
  row[0] = row[1] = std::vector<int>(n, 0);
  std::vector<int> col[2];
  col[0] = col[1] = std::vector<int>(m, 0);
  int rwrong = 0, rfixed = 0;
  int cwrong = 0, cfixed = 0;
  std::map<int, std::map<int, int> > mp;

  while(k--) {
    int x, y, t;
    std::cin >> x >> y >> t;
    x--; y--;
    int lst = mp[x][y]-1;

    rwrong -= wrong(row[0][x], row[1][x]);
    rfixed -= fixed(row[0][x], row[1][x]);
    cwrong -= wrong(col[0][y], col[1][y]);
    cfixed -= fixed(col[0][y], col[1][y]);
    if(lst == 0 || lst == 1) {
      row[(y^lst)&1][x]--;
      col[(x^lst)&1][y]--;
      type[(x^y^lst)&1]--;
    }
    if(t != -1) {
      row[(y^t)&1][x]++;
      col[(x^t)&1][y]++;
      type[(x^y^t)&1]++;
    }

    rwrong += wrong(row[0][x], row[1][x]);
    rfixed += fixed(row[0][x], row[1][x]);
    cwrong += wrong(col[0][y], col[1][y]);
    cfixed += fixed(col[0][y], col[1][y]);

    mp[x][y] = t+1;

    int ans = 0;
    if(rwrong == 0)
      ans = (ans + p2[n-rfixed])%MOD;
    if(cwrong == 0)
      ans = (ans + p2[m-cfixed])%MOD;
    if(!wrong(type[0], type[1]))
      ans = (ans - (1 + (type[0] == 0 && type[1] == 0)) + MOD)%MOD;
    std::cout << ans << std::endl;
  }

  return 0;
}