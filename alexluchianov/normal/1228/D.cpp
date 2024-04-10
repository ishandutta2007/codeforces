#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int const modulo = 1000000007;
vector<int> g[1 + nmax];
int edge[1 + nmax][2];
int team[1 + nmax];
int seen[1 + nmax];
int n, m;

void addteam(int node, int color){
  for(int i = 1;i <= n; i++)
    seen[i] = 0;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    seen[to] = 1;
  }
  for(int i = 1;i <= n ;i++)
    if(seen[i] == 0)
      team[i] = color;
}

bool valid(){
  int scount[4] = {0};

  for(int i = 1;i <= n; i++) {
    if(1 <= team[i] && team[i] <= 3)
      scount[team[i]]++;
    else
      return 0;
  }

  for(int i = 1;i <= m; i++){
    if(team[edge[i][0]] == team[edge[i][1]] )
      return 0;
  }

  return 0 < scount[1] && 0 < scount[2] && 0 < scount[3] && (1LL * n * (n - 1) / 2 - 1LL * scount[1] * (scount[1] - 1) / 2 - 1LL * scount[2] * (scount[2] - 1) / 2 - 1LL * scount[3] * (scount[3] - 1) / 2 )== m;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    cin >> edge[i][0] >> edge[i][1];
    g[edge[i][0]].push_back(edge[i][1]);
    g[edge[i][1]].push_back(edge[i][0]);
  }

  int colors = 0;
  for(int i = 1;i <= n; i++)
    if(team[i] == 0)
      addteam(i, ++colors);
  if(valid() == 0)
    cout << "-1";
  else{
    for(int i = 1;i <= n; i++)
      cout << team[i] << " ";
  }

  return 0;
}