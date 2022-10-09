#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 1000;

class FenwickTree2d{
private:
  int n;
  int m;
  vector<vector<ll>> aib;
public:
  FenwickTree2d(int n_ = 0, int m_ = 0){
    n = n_;
    m = m_;
    aib.resize(1 + n);
    for(int i = 1;i <= n; i++)
      aib[i].resize(1 + m);
  }
  void update(int x, int y, ll val){
    for(int x2 = x; x2 <= n; x2 += (x2 ^ (x2 & (x2 - 1))))
      for(int y2 = y; y2 <= m; y2 += (y2 ^ (y2 & (y2 - 1))))
        aib[x2][y2] ^= val;
  }
  ll query(int x, int y){
    ll result = 0;
    for(int x2 = x; 0 < x2; x2 = (x2 & (x2 - 1)))
      for(int y2 = y; 0 < y2; y2 = (y2 & (y2 - 1)))
        result ^= aib[x2][y2];
    return result;
  }
};

FenwickTree2d aib[2][2];

ll querysum(int x, int y){
  return aib[x % 2][y % 2].query(x, y);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2;j++)
      aib[i][j] = FenwickTree2d(n, n);

  for(int i = 1;i <= m; i++){
    int op;
    cin >> op;
    if(op == 2){
      int x, y, x2, y2;
      ll val;
      cin >> x >> y >> x2 >> y2 >> val;
      aib[x % 2][y % 2].update(x, y, val);
      aib[(x2 + 1) % 2][y % 2].update(x2 + 1, y, val);
      aib[x % 2][(y2 + 1) % 2].update(x, y2 + 1, val);
      aib[(x2 + 1) % 2][(y2 + 1) % 2].update(x2 + 1, y2 + 1, val);
    } else {
      int x, y, x2, y2;
      cin >> x >> y >> x2 >> y2;
      ll result = querysum(x2, y2) ^
                   querysum(x - 1, y2) ^
                   querysum(x2, y - 1) ^
                   querysum(x - 1, y - 1);
      cout << result << '\n';
    }
  }
  return 0;
}