#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>

using namespace std;

int const nmax = 100000;
int v[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n;i++)
    cin >> v[i];
  while(q--){
    int p;
    cin >> p;
    int x, y, val;
    cin >> x >> y >> val;

    auto pos = v + x - 1;
    y = y - x + 1;
    //cout << y << '\n';

    if(p == 1) {
      while(y % 4){
        y--;
        pos[y] -= (val < pos[y]) ? (val) : (0);
      }
      y /= 4;
      while(0 < y){
        pos[0] -= (val < pos[0]) ? (val) : (0);
        pos[1] -= (val < pos[1]) ? (val) : (0);
        pos[2] -= (val < pos[2]) ? (val) : (0);
        pos[3] -= (val < pos[3]) ? (val) : (0);
        pos += 4;
        y--;
      }
    } else {
      int ans = 0;
      while(y % 4){
        y--;
        if(val == pos[y])
          ans++;
      }
      y /= 4;
      while(y--){
        ans += (val == pos[0]) + (val == pos[1]) + (val == pos[2]) + (val == pos[3]);
        pos += 4;
      }
      cout << ans << '\n';
    }
    /*
    for(int j = 0;j < n;j++)
      cout << v[j] << " " ;
    cout << '\n';
    */
  }
  return 0;
}