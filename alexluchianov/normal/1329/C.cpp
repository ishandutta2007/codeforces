#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = (1 << 20);
int const inf = 1000000000;

int v[1 + nmax], seen[1 + nmax];

vector<pair<int,int>> append(vector<pair<int,int>> a, vector<pair<int,int>> b){
  vector<pair<int,int>> sol;
  sol.resize(a.size() + b.size());
  merge(a.begin(), a.end(), b.begin(), b.end(), sol.begin());
  return sol;
}

vector<pair<int,int>> dfs(int node, int lim, int level, int &smax){
  vector<pair<int,int>> sol;
  if(lim <= node)
    return sol;
  else {
    int smax2 = 0;

    sol.push_back({v[node], node});
    sol = append(sol, dfs(node * 2, lim, level - 1, smax2));
    sol = append(sol, dfs(node * 2 + 1, lim, level - 1, smax2));
    smax = max(smax, smax2);

    if(0 < level){
      for(int i = 0; i < sol.size(); i++){
        if(smax2 <= sol[i].first){
          seen[sol[i].second] = 1;
          smax = max(smax, sol[i].first);
          sol.erase(sol.begin() + i);
          break;
        }
      }
    }
  }
  return sol;
}

void solve(){
  int h, g;
  cin >> h >> g;
  for(int i = 1; i < (1 << h); i++) {
    cin >> v[i];
    seen[i] = 0;
  }
  int smin;
  dfs(1, (1 << h), g, smin);
  ll result = 0;
  for(int i = 1;i < (1 << h); i++)
    result += seen[i] * v[i];
  cout << result << '\n';
  for(int i = (1 << h) - 1; 1 <= i; i--)
    if(seen[i] == 0)
      cout << i << " ";
  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}