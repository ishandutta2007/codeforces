#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const modulo = 1000000007;

vector<int> g[1 + nmax];
vector<pair<int,int>> restrict;
int mult[1 + nmax];

void dfs(int node, int color){
  mult[node] = color;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(mult[to] == 0)
      dfs(to, color);
  }
}

int seen[1 + nmax];

vector<int> g2[1 + nmax];

void solve(int node, int& fatal, int color){
  seen[node] = color;
  for(int h = 0; h < g2[node].size(); h++){
    int to = g2[node][h];
    if(to != node) {
      if(seen[to] == 0)
        solve(to, fatal, 3 - color);
      else if(seen[to] == seen[node])
        fatal = 1;
    }
  }
}

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y, type;
    cin >> x >> y >> type;
    if(type == 1){
      g[x].push_back(y);
      g[y].push_back(x);
    } else
      restrict.push_back({x, y});
  }

  int ptr = 0;
  for(int i = 1;i <= n; i++)
    if(mult[i] == 0)
      dfs(i, ++ptr);

  for(int i = 0; i < restrict.size(); i++){
    int x = restrict[i].first, y = restrict[i].second;
    x = mult[x];
    y = mult[y];
    if(x == y) {
      cout << 0 << '\n';
      return 0;
    } else {
      g2[x].push_back(y);
      g2[y].push_back(x);
    }
  }
  int fatal = 0, components = 0;
  for(int i = 1;i <= ptr; i++)
    if(seen[i] == 0) {
      solve(i, fatal, 1);
      components++;
    }
  if(fatal == 1)
    cout << 0 << '\n';
  else
    cout << lgpow(2, components - 1);
  return 0;
}