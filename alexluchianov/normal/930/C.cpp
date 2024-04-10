#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 100000;
int v[5 + nmax];

class FenwickTree{
private:
  int n;
  vector<int> aib;
public:
  FenwickTree(int n){
    aib.resize(1 + n);
    this->n = n;
  }
  void update(int x, int val){
    while(x <= n){
      aib[x] = MAX(aib[x], val);
      x += (x ^ (x & (x - 1)));
    }
  }
  int query(int x){
    int result = 0;
    while(0 < x){
      result = MAX(result, aib[x]);
      x = (x & (x - 1));
    }
    return result;
  }
};
int cost[1 + nmax];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++){
    int x, y;
    cin >> x >> y;
    v[x]++;
    v[y + 1]--;
  }
  v[0] = 1;
  for(int i = 1;i <= m; i++)
    v[i] += v[i - 1];

  FenwickTree aib(1 + m), aib2(1 + m);
  for(int i = 1;i <= m; i++) {
    cost[i] = aib.query(v[i]) + 1;
    aib.update(v[i], cost[i]);
  }
  int result = 0;
  for(int i = m; 1 <= i; i--){
    int result2 = aib2.query(v[i]);
    aib2.update(v[i], result2 + 1);
    result = MAX(result, result2 + cost[i]);
  }
  cout << result;
  return 0;
}