#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 300000;
vector<int> g[1 + nmax];
vector<pair<int,int>> endin[1 + nmax], startin[1 + nmax];

struct AdvancedSet{
public:
  ll offset = 0;
  multiset<ll> myset;
  map<int,ll> coef;
  AdvancedSet(){
    offset = 0;
    myset.clear();
    coef.clear();
  }
  void _raise(ll val){
    offset += val;
  }
  void _insert(int id, ll val){
    val -= offset;
    myset.insert(val);
    coef[id] = val;
  }
  void _erase(int id){
    myset.erase(myset.find(coef[id]));
    coef.erase(id);
  }
  bool isempty(){
    return 0 == myset.size();
  }
  ll extractmin(){
    return *myset.begin() + offset;
  }
  int _size(){
    return myset.size();
  }
};
AdvancedSet myset[1 + nmax];

void addto(int from, int to){
  if(myset[to]._size() < myset[from]._size())
    swap(myset[from], myset[to]);

  for(map<int,ll>::iterator it = myset[from].coef.begin(); it != myset[from].coef.end(); it++)
    myset[to]._insert(it->first, it->second + myset[from].offset);
}

void dfs(int node, int parent){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }
  ll result = 0;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
    if(myset[to].isempty() == 1){
      cout << -1;
      exit(0);
    } else
      result += myset[to].extractmin();
  }

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    myset[to]._raise(result - myset[to].extractmin());
    addto(to, node);
  }

  for(int h = 0; h < startin[node].size(); h++)
    myset[node]._insert(startin[node][h].first, result + startin[node][h].second);
  for(int h = 0; h < endin[node].size(); h++)
    myset[node]._erase(endin[node][h].first);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= m; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    startin[x].push_back({i, cost});
    endin[y].push_back({i, cost});
  }
  startin[1].push_back({0, 0});
  dfs(1, 0);
  cout << myset[1].extractmin();
  return 0;
}