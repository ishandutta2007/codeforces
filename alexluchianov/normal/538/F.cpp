#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax];
struct Query{
  int id;
  int x;
  int y;
  int val;
  bool operator < (Query const &a) const{
    return val < a.val;
  }
};

class Fenwick{
private:
  int n;
  vector<int> aib;
public:
  Fenwick(int n){
    this->n = n;
    aib.resize(1 + n);
  }
  void update(int x, int val){
    if(x == 0)
      return ;
    while(x <= n){
      aib[x] += val;
      x += (x ^ (x & (x - 1)));
    }
  }
  int query(int x){
    int result = 0;
    while(0 < x){
      result += aib[x];
      x = x & (x - 1);
    }
    return result;
  }
};

vector<Query> queries;

void solve(int k, int n){
  for(int i = 1;i <= n;i++)
    if(k * (i - 1) + 2 <= n)
      queries.push_back({k, k * (i - 1) + 2, MIN(n, k * i + 1), v[i] - 1});
    else
      break;
}
int ind[1 + nmax];
ll sol[1 + nmax];

bool compare(int x, int y){
  return v[x] < v[y];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1; i < n; i++)
    solve(i, n);
  for(int i = 1; i <= n; i++)
    ind[i] = i;
  sort(ind + 1, ind + n + 1, compare);
  sort(queries.begin(), queries.end());
  int ptr = 0;
  Fenwick aib(n);

  for(int i = 0; i < queries.size(); i++){
    while(ptr < n && v[ind[ptr + 1]] <= queries[i].val)
      aib.update(ind[++ptr], 1);
    sol[queries[i].id] += aib.query(queries[i].y) - aib.query(queries[i].x - 1);
  }
  for(int i = 1;i < n; i++)
    cout << sol[i] << '\n';
  return 0;
}