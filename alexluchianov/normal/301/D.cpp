#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int frec[1 + nmax], v[1 + nmax];

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
      x = (x & (x - 1));
    }
    return result;
  }
};

vector<int> update[1 + nmax];
vector<pair<int,int>> query[1 + nmax];
int sol[1 + nmax];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++){
    cin >> v[i];
    frec[v[i]] = i;
  }
  Fenwick aib(n);
  for(int i = 1;i <= n; i++)
    for(int j = i; j <= n; j += i){
      int x, y;
      x = frec[i];
      y = frec[j];
      if(y < x)
        swap(x, y);
      update[x].push_back(y);
    }

  for(int i = 1;i <= m ;i++){
    int x, y;
    cin >> x >> y;
    query[x].push_back({y, i});
  }

  for(int i = n; 1 <= i; i--){
    for(int h = 0; h < update[i].size(); h++)
      aib.update(update[i][h], 1);

    for(int h = 0; h < query[i].size(); h++)
      sol[query[i][h].second] = aib.query(query[i][h].first);
  }
  for(int i = 1;i <= m; i++)
    cout << sol[i] << '\n';
  return 0;
}