#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  ll n, p, w, d;
  cin >> n >> p >> w >> d;
  for(int i = 0; i < w; i++){
    ll y = i;
    ll x = (p - i * d) / w;
    if(x + y <= n && (x * w + d * y) == p && 0 <= x && 0 <= y) {
      cout << x << " " << y << " "<< n - x - y << '\n';
      return ;
    }
  }
  cout << -1;
}

int main()
{
  solve();
  return 0;
}