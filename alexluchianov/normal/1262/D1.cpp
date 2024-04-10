#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const nmax = 200000;
int v[1 + nmax];

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

  int binarysearch(int target){///find the first position with target <= sum[x]
    if(target == 0)
      return 0;
    int x = 0;
    for(int jump = 20; 0 <= jump; jump--){
      if(x + (1 << jump) <= n && aib[x + (1 << jump)] < target){
        target -= aib[x + (1 << jump)];
        x += (1 << jump);
      }
    }
    return x + 1;
  }
};

struct Number{
  int pos;
  int val;
  bool operator < (Number const &a) const{
    if(val != a.val)
      return val < a.val;
    else
      return a.pos < pos;
  }
};

struct Query{
  int id;
  int pos;
  int time;
  bool operator < (Query const &a) const{
    if(time != a.time)
      return time < a.time;
    else
      return id < a.id;
  }
};
Number update[1 + nmax];
int sol[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    update[i] = {i, v[i]};
  }
  sort(update + 1, update + n + 1);
  reverse(update + 1, update + n + 1);
  Fenwick aib(1 + n);

  int m;
  cin >> m;
  vector<Query> query;
  for(int i = 1;i <= m; i++){
    int pos, time;
    cin >> pos >> time;
    query.push_back({i, time, pos});
  }
  sort(query.begin(), query.end());
  int ptr = 0;
  for(int i = 0; i < query.size(); i++){
    Query current = query[i];
    while(ptr < current.time)
      aib.update(update[++ptr].pos, 1);
    sol[current.id] = v[aib.binarysearch(current.pos)];
  }

  for(int i = 1;i <= m; i++)
    cout << sol[i] << '\n';
  return 0;
}