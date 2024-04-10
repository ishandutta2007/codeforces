#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
int const bits = 60;
int const modulo = 1000000007;

class IndependentSet{
private:
  int n = 0;
  vector<int> rep;
  vector<ll> v;
public:
  ll reduce(ll number){
    for(int i = 0; i < v.size(); i++)
      if(0 < ((1 << rep[i]) & number))
        number ^= v[i];
    return number;
  }

  void addset(ll number){
    number = reduce(number);
    if(0 == number)
      return ;
    n++;
    for(int i = 0; i < bits; i++)
      if(0 < ((1 << i) & number)) {
        rep.push_back(i);
        v.push_back(number);
        return ;
      }
  }
  int getsz(){
    return n;
  }
};

vector<pair<int,int>> query[1 + nmax];
int v[1 + nmax], sol[1 + nmax];

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a,b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int main()
{
  int n, q;
  cin >> n >> q;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= q; i++){
    int time, val;
    cin >> time >> val;
    query[time].push_back({val, i});
  }

  IndependentSet myset;
  for(int i = 1;i <= n; i++){
    myset.addset(v[i]);
    for(int h = 0; h < query[i].size(); h++){
      pair<int,int> ask = query[i][h];
      if(0 < myset.reduce(ask.first))
        sol[ask.second] = 0;
      else
        sol[ask.second] = lgpow(2, i - myset.getsz());
    }
  }
  for(int i = 1;i <= q; i++)
    cout << sol[i] << '\n';

  return 0;
}