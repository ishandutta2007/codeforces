#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 2505

using namespace std;
typedef long long ll;

ll n;
struct Point{
  ll x,y;
  Point(ll x = 0, ll y = 0): x(x), y(y) {}
  Point operator - (Point p){
    return Point(x - p.x,y - p.y);
  }
};
typedef Point Vector;
ll det(Vector a,Vector b){
  return a.x * b.y - a.y * b.x;
}
bool cmp_pol(Vector a,Vector b){
  bool a_up = (a.y > 0 || (a.y == 0 && a.x < 0));
  bool b_up = (b.y > 0 || (b.y == 0 && b.x < 0));
  if(a_up ^ b_up) return a_up < b_up;
  return det(a,b) > 0;
}
Point p[maxn];
vector <Point> ps;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 1;i <= n;i++) cin >> p[i].x >> p[i].y;
  ll ans = 0;
  for(int i = 1;i <= n;i++){
    ps.clear();
    for(int j = 1;j <= n;j++){
      if(i == j) continue;
      ps.push_back(p[j] - p[i]);
    }
    sort(ps.begin(),ps.end(),cmp_pol);
    int k = 0, m = n - 1;
    for(int j = 0;j < m;j++){
      if(k == j) k = (k + 1) % m;
      while(det(ps[j],ps[k]) > 0) k = (k + 1) % m;
      ll cnt = (k - 1 - j + m) % m;
      ans += cnt * (cnt - 1) / 2;
    }
  }
  ans = n * (n - 1) * (n - 2) / 6 * (n - 3) - ans;
  cout << ans * (n - 4) / 2 << endl;
  return 0;
}