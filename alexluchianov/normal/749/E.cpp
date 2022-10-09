#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

using ll = long long;
using ld = long double;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

class FenwickTree{
private:
  int n;
  vector<ld> aib;
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
  ld query(int x){
    ll result = 0;
    while(0 < x){
      result += aib[x];
      x = (x & (x - 1));
    }
    return result;
  }
};

int v[1 + nmax];
int n;
int main()
{
  cin >> n;
  ld total = 1LL * n * (n + 1) / 2;
  for(int i = 1; i <= n; i++)
    cin >> v[i];
  FenwickTree aib(n), aib2(n);
  ld result = 0, sum = 0;

  for(int i = 1;i <= n; i++){
    ld cand = aib2.query(n) - aib2.query(v[i]);
    result += (total * cand - (aib.query(n) - aib.query(v[i])) * (n - i + 1.0));
    result += aib.query(n) * (n - i + 1.0) / 2.0;
    aib.update(v[i], i);
    aib2.update(v[i], 1);
  }

  cout << setprecision(13) << fixed << result / total;
  return 0;
}