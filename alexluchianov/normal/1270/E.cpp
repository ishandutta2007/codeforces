#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
ll const inf = 1000000;

struct Point{
  ll x;
  ll y;
} v[1 + nmax];

int main()
{
  ll n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i].x >> v[i].y;
  while(true){
    ll odd = 0;
    ll xmin = v[1].x, ymin = v[1].y;
    for(int i = 1;i <= n; i++){
      xmin = MIN(xmin, v[i].x);
      ymin = MIN(ymin, v[i].y);
    }
    for(int i = 1;i <= n; i++){
      v[i].x -= xmin;
      v[i].y -= ymin;
    }

    for(int i = 1;i <= n; i++)
      odd += (v[i].x + v[i].y) % 2;
    if(odd < n && 0 < odd){
      cout << odd << '\n';
      for(int i = 1;i <= n; i++)
        if((v[i].x + v[i].y) % 2 == 1)
          cout << i << " ";
      return 0;
    }
    if(n == odd)
      for(int i = 1;i <= n; i++)
        v[i].x++;
    for(int i = 1;i <= n; i++){
      ll sumx = (v[i].x + v[i].y) / 2;
      ll sumy = (v[i].x - v[i].y) / 2;
      v[i].x = sumx;
      v[i].y = sumy;
    }
  }
  return 0;
}