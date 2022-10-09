#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const nmax = 50;
int id[1 + nmax][1 + nmax];
int id2[1 + nmax][1 + nmax];

void makevertical(int x, int y, vector<pair<int,int>> &sol);
void makeorizontal(int x, int y, vector<pair<int,int>> &sol);


void makevertical(int x, int y, vector<pair<int,int>> &sol){
  if(id[x][y] == id[x + 1][y])
    return ;
  else {
    makeorizontal(x + 1, y, sol);
    sol.push_back({x, y});
    swap(id[x + 1][y], id[x][y + 1]);
  }
}

void makeorizontal(int x, int y, vector<pair<int,int>> &sol){
  if(id[x][y] == id[x][y + 1])
    return ;
  else {
    makevertical(x, y + 1, sol);
    sol.push_back({x, y});
    swap(id[x][y], id[x + 1][y + 1]);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  int ptr = 0;
  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= m; j++) {
      char ch;
      cin >> ch;
      if(ch == 'L')
        id[i][j] = ++ptr;
      else if(ch == 'R')
        id[i][j] = id[i][j - 1];
      else if(ch == 'U')
        id[i][j] = ++ptr;
      else
        id[i][j] = id[i - 1][j];
    }
  }

  int change = 0;
  if(n % 2 == 1){
    change = 1;
    for(int i = 1;i <= n; i++)
      for(int j = 1;j <= m; j++)
        id2[j][i] = id[i][j];
    swap(n, m);
    for(int i = 1; i <= n; i++)
      for(int j = 1;j <= m; j++)
        id[i][j] = id2[i][j];
  }
  vector<pair<int,int>> sol1, sol2;

  for(int j = 1;j <= m; j++)
    for(int i = 1;i <= n; i++)
      if(id[i][j] == id[i][j + 1])
        makevertical(i, j, sol1);

  if(change == 1) {
    change = 0;
    swap(n, m);
  }
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++) {
      char ch;
      cin >> ch;
      if(ch == 'L')
        id[i][j] = ++ptr;
      else if(ch == 'R')
        id[i][j] = id[i][j - 1];
      else if(ch == 'U')
        id[i][j] = ++ptr;
      else
        id[i][j] = id[i - 1][j];
    }
  change = 0;
  if(n % 2 == 1){
    change = 1;
    for(int i = 1;i <= n; i++)
      for(int j = 1;j <= m; j++)
        id2[j][i] = id[i][j];
    swap(n, m);
    for(int i = 1; i <= n; i++)
      for(int j = 1;j <= m; j++)
        id[i][j] = id2[i][j];
  }

  for(int j = 1;j <= m; j++)
    for(int i = 1;i <= n; i++)
      if(id[i][j] == id[i][j + 1])
        makevertical(i, j, sol2);

  reverse(sol2.begin(), sol2.end());
  sol1.insert(sol1.end(), sol2.begin(), sol2.end());

  cout << sol1.size() << '\n';
  for(int i = 0; i < sol1.size(); i++){
    if(change == 1)
      swap(sol1[i].first, sol1[i].second);
    cout << sol1[i].first << " " << sol1[i].second << '\n';
  }
  return 0;
}