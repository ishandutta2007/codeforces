#include <iostream>

using namespace std;

using ll = long long;

ll lgpow(ll a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    ll result = lgpow(a , b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}

void solve(){
  ll n;
  cin >> n;
  int lim = 0;
  while(lgpow(3, lim) < n)
    lim++;
  ll x = 0;
  for(int i = lim; 0 < i; i--){
    if(x + (lgpow(3, i) - 1) / 2 < n)
      x += lgpow(3, i);
  }
  if(x < n)
    x++;
  cout << x << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}