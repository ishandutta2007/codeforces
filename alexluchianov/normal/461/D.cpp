#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const modulo = 1000000007;

struct Edge{
  int to;
  int cost;
};
vector<Edge> g[1 + nmax], g2[1 + nmax];
int seen[1 + nmax], seen2[1 + nmax];

void dfs(int node, bool &fatal, int acc){
  seen[node] = acc;
  for(int h = 0; h < g[node].size(); h++){
    Edge e = g[node][h];
    if(seen[e.to] == -1)
      dfs(e.to, fatal, acc ^ e.cost);
    else if(seen[e.to] != (acc ^ e.cost)) {
      fatal = true;
    }
  }
}

void dfs2(int node, bool &fatal, int acc){
  seen2[node] = acc;
  for(int h = 0; h < g2[node].size(); h++){
    Edge e = g2[node][h];
    if(seen2[e.to] == -1)
      dfs2(e.to, fatal, acc ^ e.cost);
    else if(seen2[e.to] != (acc ^ e.cost))
      fatal = true;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    seen[i] = seen2[i] = -1;

  int colors = (n + 1) / 2, colors2 = n / 2;

  for(int i = 1;i <= k; i++){
    int x, y;
    char ch;
    cin >> x >> y >> ch;
    int val;
    if(ch == 'o')
      val = 1;
    else
      val = 0;
    if((x + y) % 2 == 0){
      int from = fabs(x - y) / 2;
      int to = (x + y) / 2;
      if(colors < to)
        to = colors * 2 + !(n % 2) - to;

      g[from].push_back({to, val});
      g[to].push_back({from, val});
      //cout << "Edge:" << from << "->" << to << " " << val << '\n';
    } else {
      int from = (fabs(x - y) - 1) / 2;
      int to = (x + y) / 2;
      if(colors2 < to)
        to = colors2 * 2 + (n % 2) - to;

      g2[from].push_back({to, val});
      g2[to].push_back({from, val});
      //cout << "Edge2:" << from << "->" << to << " " << val << '\n';
    }
  }

  int result = 1;
  bool fatal = false;

  dfs(0, fatal, 0);

  for(int i = 1;i <= colors; i++)
    if(seen[i] == -1) {
      dfs(i, fatal, 0);
      result = 1LL * result * 2 % modulo;
    }

  dfs2(0, fatal, 0);

 // cout << colors2 << '\n';
  for(int i = 1;i <= colors2; i++)
    if(seen2[i] == -1){
      dfs2(i, fatal, 0);
      result = 1LL * result * 2 % modulo;
    }

  if(fatal == false)
    cout << result;
  else
    cout << 0;
  return 0;
}