#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
  cerr << "[";
  for (auto e : aux) cerr << e << ' ';
  cerr << "]";
  return cerr;
}

const int maxN = 200011;

int n, k, x, y;
vector<int> adj[maxN], nodes;

int dfs(int node, int parent, int lvl) {
  int weight = 1;

  for (auto to: adj[node]) {
    if (to == parent) continue;
    weight += dfs(to, node, lvl + 1);
  }

  nodes.pb(lvl - weight);
  return weight;
}

int main()
{
  //freopen("test.in", "r", stdin);

  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    adj[x].pb(y);
    adj[y].pb(x);
  }

  dfs(1, 0, 1);
  sort(nodes.begin(), nodes.end());

  //for (auto x: nodes) cerr << x << ' ';

  ll answer = 0;
  for (int i = 0; i < k; i++) 
    answer += nodes[n - i - 1];

  printf("%lld\n", answer);

  return 0;
}