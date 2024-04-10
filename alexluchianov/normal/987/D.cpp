#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int const nmax = 100000;
int const kmax = 100;

vector < int > g[5 + nmax];

int color[5 + nmax];
int cost[5 + nmax][5 + kmax];

int n , m ;

void fillfor(int cul){
  queue < int > q;

  for(int i = 1 ; i <= n ;i++){
    if(color[i] == cul){
      cost[i][cul] = 0;
      q.push(i);
    } else
      cost[i][cul] = -1;
  }
  while(0 < q.size()){
    int node = q.front();
    q.pop();
    for(int h = 0 ; h < g[node].size() ; h++){
      int to = g[node][h];
      if(cost[to][cul] == -1){
        cost[to][cul] = cost[node][cul] + 1;
        q.push(to);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();

  int k , q;
  cin >> n >> m >> k >> q;
  for(int i = 1 ; i <= n ;i++)
    cin >> color[i];
  for(int i = 1 ; i <= m ;i++){
    int x , y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1 ; i <= k ;i++)
    fillfor(i);
  for(int i = 1 ; i <= n ;i++){
    sort(cost[i] + 1 , cost[i] + k + 1);
    int result = 0;
    for(int j = 1 ;j <= q ;j++){
      result += cost[i][j];
    }
    cout << result << " ";
  }
  return 0;
}