#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 40000;
int const base = 10000019;
int const modulo = 1000000007;
int const lgmax = 20;
int v[1 + nmax], w[1 + nmax], start[1 + nmax], stop[1 + nmax];
int query[1 + nmax];

int dp[1 + lgmax][1 + nmax];

void update(int level, int k, int cost, int weight){
  for(int i = k; weight <= i; i--)
    dp[level][i] = max(dp[level][i], dp[level][i - weight] + cost);
}

vector<pair<int,int>> g[1 + nmax * 4];

void updatetree(int node, int from, int to, int x, int y, pair<int,int> val){
  if(from == x && to == y)
    g[node].push_back(val);
  else {
    int mid = (from + to) / 2;
    if(x <= mid)
      updatetree(node * 2, from, mid, x, MIN(mid, y), val);
    if(mid + 1 <= y)
      updatetree(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
  }
}

int extractsol(int k, int level){
  int result = 0;
  for(int i = k; 1 <= i; i--)
    result = (1LL * result * base + dp[level][i]) % modulo;
  return result;
}

void dfs(int node, int from, int to, int k, int level){
  for(int i = 1;i <= k; i++)
    dp[level][i] = dp[level - 1][i];

  for(int h = 0; h < g[node].size(); h++)
    update(level, k, g[node][h].first, g[node][h].second);

  if(from < to){
    int mid = (from + to) / 2;
    dfs(node * 2, from, mid, k, level + 1);
    dfs(node * 2 + 1, mid + 1, to, k, level + 1);
  } else if(0 < query[from])
    cout << extractsol(k, level) << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  int time = 0;
  for(int i = 1;i <= n; i++) {
    cin >> v[i] >> w[i];
    start[i] = 1;
  }
  int q;
  cin >> q;
  for(int i = 1; i <= q; i++){
    int op;
    cin >> op;
    ++time;
    if(op == 1){
      ++n;
      cin >> v[n] >> w[n];
      start[n] = time;
    } else if(op == 2){
      int x;
      cin >> x;
      stop[x] = time;
    } else if(op == 3){
      query[time] = 1;
    }
  }

  for(int i = 1;i <= n; i++) {
    if(stop[i] == 0)
      stop[i] = time;
    updatetree(1, 1, time, start[i], stop[i], {v[i], w[i]});
  }

  dfs(1, 1, time, k, 1);

  return 0;
}