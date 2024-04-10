#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
using ld = long double;
int const nmax = 300000;

pair<int,int> form(int x, int y, int x2, int y2){
  int x3 = x - x2;
  int y3 = y - y2;
  if(x3 == 0)
    return {0, y3 / abs(y3)};
  else if(y3 == 0)
    return {x3 / abs(x3), 0};
  else {
    int d = __gcd(abs(x3), abs(y3));
    return {x3 / d, y3 / d};
  }
}
map<pair<int,int>, int> frec;

vector<pair<int,int>> last;

class FenwickTree{
private:
  int n;
  vector<int> aib;
public:
  FenwickTree(int n_){
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val){
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))) )
      aib[x] += val;
  }
  int query(int pos){
    int result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result;
  }
};

struct Query{
  int x;
  int y;
  int id;
  bool operator < (Query const &a) const{
    return y < a.y;
  }
};

int sol[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    int m;
    cin >> m;
    vector<pair<int,int>> v;
    for(int j = 0; j < m; j++){
      int x, y;
      cin >> x >> y;
      v.push_back({x, y});
    }
    for(int j = 0;j < m; j++){
      pair<int,int> edge = form(v[j].first, v[j].second, v[(j + 1) % m].first, v[(j + 1) % m].second);
      last.push_back({i, frec[edge]});
      frec[edge] = i;
    }
  }

  int q;
  cin >> q;
  vector<Query> queries;
  for(int i = 1;i <= q; i++){
    int x, y;
    cin >> x >> y;
    queries.push_back({x, y, i});
  }

  sort(queries.begin(), queries.end());
  int ptr = 0;
  FenwickTree aib(n);
  for(int i = 0; i < queries.size(); i++){
    int x = queries[i].x;
    int y = queries[i].y;
    while(ptr < last.size() && last[ptr].first <= y) {
      if(0 < last[ptr].second) {
        aib.update(last[ptr].second , -1);
      }
      aib.update(last[ptr].first, 1);
      ptr++;
    }
    sol[queries[i].id] = (aib.query(y) - aib.query(x - 1));
  }

  for(int i = 1; i <= q; i++)
    cout << sol[i] << '\n';
  return 0;
}