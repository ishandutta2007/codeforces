#include <iostream>
#include <vector>

#define int long long

const int MAXN = 105;

int dp[MAXN][MAXN]; // dp[i][j] minimum length of path starting from i visiting j
                    // distinct nodes in i's subtree
int optn[MAXN]; // optn[i][j] denotes optimal last child for dp[i][j]
int optc[MAXN]; // optc[i][j] denotes optimal number of nodes to be visited
                      // by children other than last child
int sz[MAXN];
int bestc[MAXN];
std::vector<int> output;
const int INF = 10000;
int n;
std::vector<int> Adj[MAXN];
int distn;

void printR(int u, int p, int av, int rem) {
  distn++; 

  for(int j : Adj[u]) {
    if(j == av || distn == rem)
      continue;

    output.push_back(j);
    printR(j, u, av, rem);
    output.push_back(u);
  }
}

void printA(int u, int p, int k) {
  //std::cout << u << " " << k << " " << dp[u][k] << " " << optn[u][k] << " " << optc[u][k] << std::endl;
  if(k == 0)
    return;
  distn = 0;
  int delx = std::max(0ll, k-sz[optn[u]]);
  printR(u, p, optn[u], delx+1);
  k -= delx;

  output.push_back(optn[u]);
  k--;

  printA(optn[u], u, k);
}

int dfsc(int u, int p) {
  sz[u] = 1;
  int maxc = 0;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    int next = dfsc(j, u);
    if(next+1 > maxc) {
      optn[u] = j;
      maxc = next+1;
    }
    sz[u] += sz[j];
  }
  return maxc;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int k;
    std::cin >> n >> k;

    output.clear();
    output.push_back(0);
    for(int i = 0; i < n; i++)
      Adj[i].clear();

    for(int i = 1; i < n; i++) {
      int x;
      std::cin >> x;
      x--;
      Adj[x].push_back(i);
    }

    dfsc(0, -1);
    printA(0, -1, k-1);

    std::cout << ((int)output.size())-1 << std::endl;
    for(int j : output)
      std::cout << j+1 << " ";
    std::cout << std::endl;
  }

  return 0;
}