#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int const nmax = 100000;
vector<int> g[1 + nmax];

double result = 0;

void dfs(int node, int parent, int acc){
  result += 1.0 / acc;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node, acc + 1);
  }
}


int main()
{
  int n;
  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0 , 1);
  cout << setprecision(10) << fixed << result;
  return 0;
}