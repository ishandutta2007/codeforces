#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo = 1000000007;
int v[1 + nmax];
int sum[1 + nmax];

class FenwickTree{
private:
  int n;
  vector<int> aib;
public:
  FenwickTree(int n){
    this->n = n;
    aib.resize(1 + n);
  }
  void update(int x, int val){
    if(x == 0)
      return ;
    while(x < n){
      aib[x] += val;
      if(modulo <= aib[x])
        aib[x] -= modulo;
      x += (x ^ (x & (x - 1)));
    }
  }
  int query(int x){
    int result = 0;
    while(0 < x){
      result += aib[x];
      if(modulo <= result)
        result -= modulo;
      x = x & (x - 1);
    }
    return result;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  FenwickTree dp(1 + nmax);
  dp.update(1, 1);
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    ll result = 1LL * (modulo + dp.query(v[i]) - sum[v[i]]) % modulo ;
    sum[v[i]] += result;
    if(modulo <= sum[v[i]])
      sum[v[i]] -= modulo;

    dp.update(v[i], 1LL * result * v[i] % modulo);
  }
  cout << (modulo + dp.query(nmax) - 1) % modulo;
  return 0;
}