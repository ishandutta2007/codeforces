#include <iostream>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
char v[5 + nmax][5 + nmax];
int seen[5 + nmax][5 + nmax];
int const iplus[4] = {0, 0, 1, -1};
int const jplus[4] = {1, -1, 0, 0};

void dfs(int x, int y){
  if(seen[x][y] == 1)
    return ;
  seen[x][y] = 1;
  for(int h = 0; h < 4; h++){
    int newx = x + iplus[h];
    int newy = y + jplus[h];
    if(v[newx][newy] == '#')
      dfs(newx, newy);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 0; i <= n + 1; i++)
    for(int j = 0; j <= m + 1; j++)
      v[i][j] = '.';

  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      cin >> v[i][j];
  int result = 0;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      if(v[i][j] == '#' && seen[i][j] == 0) {
        dfs(i, j);
        result++;
      }

  for(int i = 1;i <= n; i++) {
    int sum = 0;
    for(int j = 1;j <= m; j++)
      if(v[i][j - 1] != v[i][j])
        sum++;
    if(2 < sum) {
      cout << -1;
      return 0;
    }
  }

  for(int i = 1;i <= m; i++){
    int sum = 0;
    for(int j = 1;j <= n; j++)
      if(v[j][i] != v[j - 1][i])
        sum++;
    if(2 < sum){
      cout << -1;
      return 0;
    }
  }
  int emptlin = 0, emptcol = 0;

  for(int i = 1; i <= n; i++) {
    bool empt = 1;
    for(int j = 1; j <= m; j++)
      empt &= (v[i][j] == '.');
    emptlin |= empt;
  }
  for(int i = 1;i <= m; i++){
    bool empt = 1;
    for(int j = 1; j <= n; j++)
      empt &= (v[j][i] == '.');
    emptcol |= empt;
  }

  if(emptlin == emptcol)
    cout << result;
  else
    cout << -1;
  return 0;
}