#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 1000;
int const lgmax = 10;
int v[5 + nmax][5 + nmax];
int dp[5 + nmax][5 + nmax];
int lg[1 + nmax];

void computedp(int n, int m){
  for(int i = n; 1 <= i; i--)
    for(int j = m; 1 <= j; j--)
      if(v[i][j] == 0)
        dp[i][j] = 0;
      else
        dp[i][j] = MIN(dp[i + 1][j], MIN(dp[i][j + 1], dp[i + 1][j + 1])) + 1;
}
int rmq[1 + lgmax][1 + lgmax][1 + nmax][1 + nmax];

int getmax(int x, int y, int x2, int y2){
  int h1 = lg[x2 - x], h2 = lg[y2 - y];
  int result = MAX(MAX(rmq[h1][h2][x][y], rmq[h1][h2][x2 - (1 << h1) + 1][y]),
                   MAX(rmq[h1][h2][x][y2 - (1 << h2) + 1], rmq[h1][h2][x2 - (1 << h1) + 1][y2 - (1 << h2) + 1])
                   );
  return result;
}

void computermq(int n, int m){
  for(int i = 1;i <= n; i++)
    for(int j = 1 ;j <= m; j++)
      rmq[0][0][i][j] = dp[i][j];
  for(int h1 = 0; h1 < lgmax; h1++)
    for(int h2 = 0; h2 < lgmax; h2++)
      if(0 < h1 || 0 < h2)
        for(int i = 1;i <= n; i++)
          for(int j = 1;j <= m; j++)
            if(i + (1 << h1) - 1 <= n && j + (1 << h2) - 1 <= m)
              rmq[h1][h2][i][j] = getmax(i, j, i + (1 << h1) - 1, j + (1 << h2) - 1);
}

bool test(int x, int y, int x2, int y2, int target){
  if(x + target - 1 <= x2 && y + target - 1 <= y2)
    return target <= getmax(x, y, x2 - target + 1, y2 - target + 1);
  else
    return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 2;i <= nmax; i++)
    lg[i] = lg[i / 2] + 1;

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      cin >> v[i][j];
  computedp(n, m);
  computermq(n, m);
  int q;
  cin >> q;
  for(int i = 1;i <= q; i++) {
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;
    int target = 0;
    for(int jump = (1 << 20); 0 < jump; jump /= 2){
      if(test(x, y, x2, y2, target + jump) == 1)
        target += jump;
    }
    cout << target << '\n';
  }
  return 0;
}