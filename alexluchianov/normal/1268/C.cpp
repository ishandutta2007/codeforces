#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;

class FenwickTree{
private:
  int n;
  vector<ll> aib;
public:
  FenwickTree(int n){
    this->n = n;
    aib.resize(1 + n);
  }

  void update(int x, int val){
    while(x <= n){
      aib[x] += val;
      x += (x ^ (x & (x - 1)));
    }
  }
  ll query(int x){
    ll result = 0;
    while(0 < x){
      result += aib[x];
      x = (x & (x - 1));
    }
    return result;
  }

  ///finds first x with target <= query(x)

  int lower_than(int target){
    int x = 0;
    ll result = 0;
    for(int jump = (1 << 20); 0 < jump; jump /= 2){
      if(x + jump <= n && result + aib[x + jump] < target) {
        result += aib[x + jump];
        x += jump;
      }
    }
    return x + 1;
  }
};

int v[1 + nmax], frec[1 + nmax];

ll gauss(int x){
  return 1LL * x * (x + 1) / 2;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    frec[v[i]] = i;
  }
  FenwickTree active(n), sum(n);
  ll interncost = 0, externcost = 0;
  for(int i = 1;i <= n; i++){
    int pos = frec[i];
    active.update(pos, 1);
    sum.update(pos, pos);
    interncost += active.query(n) - active.query(pos);
    externcost = 0;
    int median = active.lower_than(i / 2 + 1);

    //cout << pos << " " << median << '\n';
    //cout << (sum.query(n) - sum.query(median)) - (i - i / 2 - 1) * median << '\n';
    //cout << median * (i / 2) - (sum.query(median - 1)) << '\n';

    externcost = (sum.query(n) - sum.query(median)) - 1LL * (i - i / 2 - 1) * median +
                 1LL * median * (i / 2) - (sum.query(median - 1));
    externcost = externcost - gauss((i - i / 2 - 1)) - gauss(i / 2);

    //cout << ":" << interncost << " " << externcost << '\n';
    cout << interncost + externcost << " " ;
  }
  return 0;
}