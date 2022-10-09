#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int const lgmax = 20;

int v[1 + nmax];
int dp[1 + lgmax][1 + lgmax];
int sol[1 + nmax];

vector<pair<int,int>> query[1 + nmax];

int main()
{
  int n, q;
  cin >> n >> q;
  for(int i = 1;i <= n; i++)
    cin >> v[i];

  for(int i = 0;i < lgmax; i++)
    for(int j = 0; j < lgmax; j++)
      dp[i][j] = 0;

  for(int i = 1;i <= q; i++){
    int x, y;
    cin >> x >> y;
    query[y].push_back({x, i});
  }

  for(int i = 1;i <= n; i++){
    int last = -1;
    for(int bit = 0; bit < lgmax; bit++)
      if(0 < (v[i] & (1 << bit))) {
        dp[bit][bit] = MAX(dp[bit][bit], i);
        if(last != -1)
          for(int bit2 = 0; bit2 < lgmax; bit2++)
            dp[last][bit2] = MAX(dp[last][bit2], dp[bit][bit2]);
        else
          last = bit;
      }

    last = -1;
    for(int bit = 0; bit < lgmax; bit++)
      if(0 < (v[i] & (1 << bit))) {
        if(last != -1)
          for(int bit2 = 0; bit2 < lgmax; bit2++)
            dp[bit][bit2] = MAX(dp[bit][bit2], dp[last][bit2]);
        last = bit;
      }

    for(int h = 0; h < query[i].size(); h++){
      int node = query[i][h].first;
      for(int bit = 0; bit < lgmax; bit++)
        if(-1 != last)
          if(0 < (v[node] & (1 << bit)))
            sol[query[i][h].second] = (node <= (dp[last][bit]));
    }
  }

  for(int i = 1;i <= q; i++)
    if(sol[i] == 1)
      cout << "Shi\n";
    else
      cout << "Fou\n";

  return 0;
}