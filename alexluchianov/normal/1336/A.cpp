#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
vector<int> g[1 + nmax];
int level[1 + nmax], sz[1 + nmax];

vector<int> scores;

void dfs(int node, int parent){
  sz[node] = 1;
  level[node] = level[parent] + 1;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent){
      dfs(to, node);
      sz[node] += sz[to];
    }
  }
  scores.push_back(level[node] - sz[node]);

}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1;i < n;i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  sort(scores.begin(), scores.end());
  reverse(scores.begin(), scores.end());
  ll result = 0;
  for(int i = 0; i < k; i++)
    result += scores[i];
  cout << result;

  return 0;
}