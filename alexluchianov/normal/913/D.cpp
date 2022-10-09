#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 200000;
int const inf = 1000000001;
int v[1 + nmax];
vector<pair<int,int>> g[1 + nmax];

namespace Magic{
  priority_queue<int> pq;
  priority_queue<int, vector<int>, greater<int> > pq2;
  int threshold;
  ll result = 0;

  void _balance(){
    while(threshold < pq.size()){
      pq2.push(pq.top());
      result -= pq.top();
      pq.pop();
    }
    while(pq.size() < threshold && 0 < pq2.size()){
      pq.push(pq2.top());
      result += pq2.top();
      pq2.pop();
    }
  }

  void _insert(int val){
    pq.push(val);
    result += val;
    _balance();
  }

  int _extract(){
    _balance();
    if(pq.size() < threshold)
      return inf;
    return result;
  }
}

void print(int k, int n){
  cout << k << '\n' << k << '\n';
  vector<pair<int,int>> sol;
  for(int i = k; i <= n; i++)
    for(int h = 0; h < g[i].size(); h++)
      sol.push_back(g[i][h]);
  sort(sol.begin(), sol.end());
  for(int i = 0; i < k; i++)
    cout << sol[i].second << " ";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, lim;
  cin >> n >> lim;
  for(int i = 1;i <= n; i++){
    int t, cost;
    cin >> t >> cost;
    g[t].push_back({cost, i});
  }

  for(int i = n; 1 <= i; i--){
    Magic::threshold = i;
    for(int h = 0; h < g[i].size(); h++)
      Magic::_insert(g[i][h].first);

    if(Magic::_extract() <= lim) {
      print(i, n);
      return 0;
    }
  }
  cout << 0 << '\n' << 0;
  return 0;
}