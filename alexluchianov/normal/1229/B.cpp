#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const modulo = 1000000007;

vector<int> g[1 + nmax];

ll v[1 + nmax];
int far[20][1 + nmax];
ll farp[20][1 + nmax];
int level[1 + nmax];

void dfs(int node, int parent){
  level[node] = level[parent] + 1;
  far[0][node] = parent;
  farp[0][node] = v[node];

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
}

int jumpttonext(int &node, ll gcd){ ///returns next node with different gcd
  int steps = 0;
  for(int h = 19; 0 <= h; h--){
    if((1 << h) <= level[node]){
      if(__gcd(gcd, farp[h][node]) == gcd){
        node = far[h][node];
        steps += (1 << h);
      }
    }
  }
  return steps;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  for(int h = 1; h < 20; h++)
    for(int i = 1;i <= n; i++) {
      far[h][i] = far[h - 1][far[h - 1][i]];
      farp[h][i] = __gcd(farp[h - 1][i], farp[h - 1][far[h - 1][i]]);
    }

  ll result = 0;
  for(int i = 1;i <= n; i++){
    int node = i;
    ll gcd = v[node];
    while(node != 0){
      result += 1LL * gcd * jumpttonext(node, gcd) % modulo;
      if(modulo <= result)
        result -= modulo;
      gcd = __gcd(gcd, v[node]);
    }
  }
  cout << result;
  return 0;
}