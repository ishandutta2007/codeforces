#include <iostream>

using namespace std;

using ll = long long;

int const nmax = 200000;
int v[1 + nmax], seen[1 + nmax], sol[1 + nmax];

int dfs(int node, int dist){
  if(seen[node] == 1)
    return dist;
  seen[node] = 1;
  sol[node] = dfs(v[node], dist + 1);
  return sol[node];
}

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    seen[i] = 0;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0)
      dfs(i, 0);
  for(int i = 1;i <= n; i++)
    cout << sol[i] << " ";
  cout << '\n';
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