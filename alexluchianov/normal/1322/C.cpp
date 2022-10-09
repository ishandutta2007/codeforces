#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;

int const nmax = 500000;
int const modulo  =  998244353;
int const modulo2 = 1000000009;

struct Number{
  int number1;
  int number2;
  Number(int val = 0){
    number1 = number2 = val;
  }

  Number(int number1_, int number2_){
    number1 = number1_;
    number2 = number2_;
  }

  Number operator + (Number const &a) const {
    return {(number1 + a.number1) % modulo, (number2 + a.number2) % modulo2};
  }
  Number operator * (Number const &a) const {
    return {1LL * number1 * a.number1 % modulo, 1LL * number2 * a.number2 % modulo2};
  }
  bool operator < (Number const &a) const {
    if(number1 != a.number1)
      return number1 < a.number1;
    else
      return number2 < a.number2;
  }
};
Number pow2[1 + nmax];

void computepow(){
  pow2[0] = 1;
  for(int i = 1;i <= nmax; i++)
    pow2[i] = pow2[i - 1] * 2;
}
Number v[1 + nmax];
ll cost[1 + nmax];

ll solve(){
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    v[i] = 0;
  for(int i = 1;i <= n; i++)
    cin >> cost[i];

  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    v[y] = v[y] + pow2[x];
  }
  map<Number, ll> frec;

  for(int i = 1;i <= n; i++)
    frec[v[i]] += cost[i];
  ll result = 0;
  for(int i = 1;i <= n; i++)
    if(0 < v[i].number1)
      result = __gcd(result, frec[v[i]]);
  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  computepow();

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    cout << solve() << '\n';
  return 0;
}