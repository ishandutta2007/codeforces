#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int v[1 + nmax];
int d[1 + nmax];

void precompute(){
  for(int i = 1;i <= nmax; i++)
    for(int j = i; j <= nmax; j += i)
      d[j]++;
}

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
    if(x == 0)
      return ;
    while(x <= n){
      aib[x] += val;
      x += x ^ (x & (x - 1));
    }
  }
  ll query(int x){
    ll result = 0;
    while(0 < x){
      result += aib[x];
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

  precompute();

  int n, q;
  cin >> n >> q;
  set<int> interest;
  FenwickTree aib(n);

  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    aib.update(i, v[i]);
    if(2 < v[i])
      interest.insert(i);
  }
  for(int i = 1;i <= q; i++){
    int op, x, y;
    cin >> op >> x >> y;

    if(op == 1){
      int last = x;
      while(true){
        set<int>::iterator it = interest.lower_bound(last);
        if(it == interest.end())
          break;

        if(*it <= y){
          int pos = *it;
          interest.erase(it);
          aib.update(pos, -v[pos]);
          v[pos] = d[v[pos]];
          aib.update(pos, v[pos]);

          if(2 < v[pos])
            interest.insert(pos);
          last = pos + 1;
        } else
          break ;
      }
    } else {
      cout << aib.query(y) - aib.query(x - 1) << '\n';
    }
  }
  return 0;
}
/*
7
1 2 5 3 4 6 7
011101
*/