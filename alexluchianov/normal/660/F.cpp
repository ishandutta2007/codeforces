#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

struct Line{
  ll a;
  ll b;
  Line(ll a = 0, ll b = 0){
    this->a = a;
    this->b = b;
  }
  ll eval(ll x){
    return a + b * x;
  }
};

class LiChao{
private:
  int n;
  vector<Line> aint;
public:
  LiChao(int n){
    this->n = n;
    aint.resize(4 * n);
  }
  void update(int node, int from, int to, Line curr){
    int mid = (from + to) / 2;
    if(aint[node].eval(mid) <= curr.eval(mid))
      swap(aint[node], curr);

    if(from < to) {
      if(aint[node].eval(from) <= curr.eval(from))
        update(node * 2, from, mid, curr);
      else
        update(node * 2 + 1, mid + 1, to, curr);
    }
  }
  ll query(int node, int from, int to, int x){
    if(from < to){
      int mid = (from + to) / 2;
      ll result = 0;
      if(x <= mid)
        result = query(node * 2, from, mid, x);
      else
        result = query(node * 2 + 1, mid + 1, to, x);
      return MAX(aint[node].eval(x), result);
    } else
      return aint[node].eval(x);
  }
};

int const nmax = 200000;
ll v[1 + nmax], f[1 + nmax], suff[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = n; 1 <= i; i--) {
    suff[i] = suff[i + 1] + v[i];
    f[i] = f[i + 1] + suff[i];
  }
  LiChao dp(n);
  ll result = 0;
  for(int i = n; 1 <= i; i--){
    dp.update(1, 1, n, {-f[i + 1] - 1LL * (i + 1) * suff[i + 1], suff[i + 1]});
    ll result2 = f[i] + dp.query(1, 1, n, i);
    if(result < result2)
      result = result2;
  }
  cout << result;
  return 0;
}