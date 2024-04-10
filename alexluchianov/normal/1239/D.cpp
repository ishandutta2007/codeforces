#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000000;
vector<int> g[1 + nmax];
int seen[1 + nmax];

int n, m;

void dfs(int node, int color, vector<int> &sol){
  if(sol[node] == -1)
    sol[node] = color;
  else
    return ;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(fabs(to - node) == n || color == 1)
      dfs(to, !color, sol);
  }
}

bool cleansol(vector<int> &sol){
  int cat = 0, man = 0;
  for(int i = 1;i <= n; i++)
    if(sol[i] == 0)
      cat++;
    else if(sol[i] == 1)
      man++;
  bool cats;
  if(cat == 0)
    cats = true;
  else
    cats = false;

  for(int i = 1;i <= n; i++)
    if(sol[i] == -1)
      if(cats == false) {
        sol[i] = 1;
        sol[i + n] = 0;
        man++;
      } else {
        sol[i] = 0;
        sol[i + n] = 1;
        cat++;
      }
  return 0 < cat && 0 < man;
}

void solve(){
  cin >> n >> m;
  for(int i = 1;i <= 2 * n; i++) {
    seen[i] = 0;
    g[i].clear();
  }

  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(n + y);
    g[n + y].push_back(x);
  }
  vector<int> sol1(1 + 2 * n, -1), sol2(1 + 2 * n, -1);
  dfs(1, 1, sol1);
  dfs(1, 0, sol2);
  vector<int> finalsol;
  if(cleansol(sol1) == 1)
    finalsol = sol1;
  if(cleansol(sol2) == 1)
    finalsol = sol2;

  if(finalsol.size() == 0)
    cout << "No\n";
  else {
    cout << "Yes\n";
    int man = 0, cat = 0;
    for(int i = 1;i <= n; i++)
      if(finalsol[i] == 1)
        man++;
      else
        cat++;
    cout << man << " " << cat << '\n';
    for(int i = 1;i <= n; i++)
      if(finalsol[i] == 1)
        cout << i << " ";
    cout << '\n';
    for(int i = 1;i <= n; i++)
      if(finalsol[i] == 0)
        cout << i << " ";
    cout << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}