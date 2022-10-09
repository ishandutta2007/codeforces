#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <queue>
#include <stack>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
vector<pair<int,int>> g[5 + nmax];

vector<ll> distances(int start, int n){
  vector<ll> dist(1 + n);
  vector<int> seen(1 + n);
  queue<int> q;
  q.push(start);
  seen[start] = 1;
  while(0 < q.size()){
    int node = q.front();
    q.pop();
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h].first, cost = g[node][h].second;
      if(seen[to] == 0){
        seen[to] = 1;
        dist[to] = dist[node] + cost;
        q.push(to);
      }
    }
  }
  return dist;
}

int farthest(vector<ll> v, int n){
  int id = 1;
  for(int i = 1;i <= n; i++)
    if(v[id] < v[i])
      id = i;
  return id;
}

ll marker[5 + nmax];

vector<int> st;
int findtarget(ll target){
  int x = 0;
  for(int jump = (1 << 17); 0 < jump; jump /= 2)
    if(x + jump < st.size() && marker[st[x + jump]] <= target)
      x += jump;
  return x;
}

int bonus[1 + nmax];

int dfs(int node, int parent, ll lim, int &result){
  int val = 1;
  st.push_back(node);
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h].first;
    if(to != parent)
      val += dfs(to, node, lim, result);
  }
  val += bonus[node];
  result = max(result, val);
  bonus[st[findtarget(marker[node] - lim - 1)]]--;
  st.pop_back();
  return val;
}

int solve(int n, int root){
  ll lim;
  cin >> lim;
  st.clear();
  st.push_back(0);
  for(int i = 1;i <= n;i++)
    bonus[i] = 0;
  int result = 1;
  dfs(root, 0, lim, result);
  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  int border = farthest(distances(1, n), n);
  int border2 = farthest(distances(border, n), n);
  vector<ll> dist1 = distances(border, n), dist2 = distances(border2, n);
  int root = 1;
  for(int i = 1;i <= n; i++) {
    marker[i] = max(dist1[i], dist2[i]);
    if(marker[i] < marker[root])
      root = i;
  }

  cin >> q;
  for(int i = 1;i <= q; i++)
    cout << solve(n, root) << '\n';
  return 0;
}