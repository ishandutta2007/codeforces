#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
using ld = long double;

int const lgmax = 20;
int const nmax = 500000;
int v[1 + nmax];

class IndependentSet{
private:
  std::vector<std::pair<int,int>> v;
public:
  int _reduce(int number){
    for(int i = 0; i < v.size(); i++)
      if(0 < (number & (1 << v[i].first)) )
        number ^= v[i].second;
    return number;
  }

  void _insert(int number){
    number = _reduce(number);
    if(0 < number)
      for(int h = lgmax; 0 <= h; h--)
        if(0 < ((1 << h) & number)) {
          v.push_back({h, number});
          break;
        }
  }

  void _insert(vector<int> number){
    for(int h = 0; h < number.size(); h++)
      _insert(number[h]);
  }

  int _max(){
    vector<int> temp;
    int result = 0;
    for(int i = 0; i < v.size(); i++)
      temp.push_back(v[i].second);
    for(int h = lgmax; 0 <= h; h--) {
      int val = 0;
      for(int i = 0; i < temp.size(); i++)
        if(0 < ((1 << h) & (temp[i])))
          val = temp[i];
      if(0 == (result & (1 << h)))
        result ^= val;
      for(int i = 0; i < temp.size(); i++)
        if(0 < ((1 << h) & temp[i]))
          temp[i] ^= val;
    }
    return result;
  }

  vector<int> extract(){
    vector<int> sol;
    for(int i = 0; i < v.size(); i++)
      sol.push_back(v[i].second);
    return sol;
  }
};

struct Query{
  int x;
  int y;
  int id;
};
IndependentSet sol[1 + nmax];

vector<int> active[1 + nmax];

void divide(int from, int to, vector<Query> queries){
  if(queries.size() == 0)
    return ;

  if(from == to)
    for(int h = 0; h < queries.size(); h++)
      sol[queries[h].id]._insert(v[from]);
  else {
    vector<Query> queriesleft, queriesright, queriesnow;
    int mid = (from + to) / 2;
    for(int i = 0; i < queries.size(); i++)
      if(queries[i].x <= mid && queries[i].y <= mid)
        queriesleft.push_back(queries[i]);
      else if(mid + 1 <= queries[i].x && mid + 1 <= queries[i].y)
        queriesright.push_back(queries[i]);
      else if(queries[i].x <= mid && mid + 1 <= queries[i].y)
        queriesnow.push_back(queries[i]);
    divide(from, mid, queriesleft);
    divide(mid + 1, to, queriesright);
    for(int i = from; i <= to; i++)
      active[i].clear();
    for(int i = 0; i < queriesnow.size(); i++) {
      active[queriesnow[i].x].push_back(queriesnow[i].id);
      active[queriesnow[i].y].push_back(queriesnow[i].id);
    }

    IndependentSet myset;
    for(int i = mid; from <= i; i--){
      myset._insert(v[i]);
      for(int h = 0; h < active[i].size(); h++)
        sol[active[i][h]]._insert(myset.extract());
    }

    myset = IndependentSet();
    for(int i = mid + 1; i <= to; i++){
      myset._insert(v[i]);
      for(int h = 0; h < active[i].size(); h++)
        sol[active[i][h]]._insert(myset.extract());
    }
  }
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
  int q;
  cin >> q;
  vector<Query> queries;
  for(int i = 1;i <= q; i++){
    int x, y;
    cin >> x >> y;
    queries.push_back({x, y, i});
  }
  divide(1, n, queries);
  for(int i = 1; i <= q; i++)
    cout << sol[i]._max() << '\n';
  return 0;
}