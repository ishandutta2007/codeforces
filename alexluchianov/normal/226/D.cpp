#include <iostream>

using namespace std;

using ll = long long;
int const nmax = 100;
int v[1 + nmax][1 + nmax];
int column[1 + nmax], line[1 + nmax];

int n, m;

void changeline(int x){
  line[x] = line[x] ^ 1;
  for(int i = 1;i <= m; i++)
    v[x][i] = -v[x][i];
}

void changecolumn(int x){
  column[x] = column[x] ^ 1;
  for(int i = 1;i <= n; i++)
    v[i][x] = -v[i][x];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      cin >> v[i][j];
  while(true){
    bool anychange = 0;
    for(int i = 1;i <= n; i++){
      ll sum = 0;
      for(int j = 1;j <= m; j++)
        sum += v[i][j];
      if(sum < 0) {
        changeline(i);
        anychange = 1;
      }
    }
    for(int i = 1;i <= m; i++){
      ll sum = 0;
      for(int j = 1; j <= n; j++)
        sum += v[j][i];
      if(sum < 0) {
        changecolumn(i);
        anychange = 1;
      }
    }
    if(anychange == 0)
      break;
  }

  int result = 0;
  for(int i = 1;i <= n; i++)
    result += line[i];
  cout << result << " " ;
  for(int i = 1;i <= n; i++)
    if(line[i] == 1)
      cout << i << " ";
  cout << '\n';

  result = 0;
  for(int i = 1;i <= m; i++)
    result += column[i];
  cout << result << " " ;
  for(int i = 1;i <= m; i++)
    if(column[i] == 1)
      cout << i << " ";

  return 0;
}