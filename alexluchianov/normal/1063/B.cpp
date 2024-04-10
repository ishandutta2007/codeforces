#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;

char v[5 + nmax][5 + nmax];

bool valid(int x , int y , int n , int m){
  return (1 <= x && x <= n) && (1 <= y && y <= m) && v[x][y] == '.';
}

int stmin[5 + nmax][5 + nmax];
int drmin[5 + nmax][5 + nmax];
int seen[5 + nmax][5 + nmax];


struct Square{
  int x;
  int y;
};

int main()
{
  int n , m;
  cin >> n >> m;
  int x , y;
  cin >> x >> y;
  int st , dr;
  cin >> st >> dr;
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= m ; j++)
      cin >> v[i][j];
  seen[x][y] = 1;
  queue<Square> q;
  q.push({x , y});

  while(0 < q.size()){
    int x = q.front().x;
    int y = q.front().y;
    q.pop();
    if(valid(x + 1 , y , n , m)){
      if(seen[x + 1][y] == 0 || stmin[x][y] < stmin[x + 1][y] ){
        seen[x + 1][y] = 1;
        stmin[x + 1][y] = stmin[x][y];
        drmin[x + 1][y] = drmin[x][y];
        q.push({x + 1 , y});
      }
    }
    if(valid(x - 1 , y , n , m)){
      if(seen[x - 1][y] == 0 || stmin[x][y] < stmin[x - 1][y] ){
        seen[x - 1][y] = 1;
        stmin[x - 1][y] = stmin[x][y];
        drmin[x - 1][y] = drmin[x][y];
        q.push({x - 1 , y});
      }
    }

    if(valid(x , y - 1, n , m)){
      if((seen[x][y - 1] == 0 || stmin[x][y] + 1 < stmin[x][y - 1]) && stmin[x][y] + 1 <= st){
        seen[x][y - 1] = 1;
        stmin[x][y - 1] = stmin[x][y] + 1;
        drmin[x][y - 1] = drmin[x][y];
        q.push({x , y - 1});
      }
    }

    if(valid(x , y  + 1, n , m)){
      if((seen[x][y + 1] == 0 || stmin[x][y] < stmin[x][y + 1]) && drmin[x][y] + 1 <= dr){
        seen[x][y + 1] = 1;
        stmin[x][y + 1] = stmin[x][y];
        drmin[x][y + 1] = drmin[x][y] + 1;
        q.push({x , y + 1});
      }
    }
  }

  int result = 0;
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= m ; j++) {
      result += seen[i][j];
    }
  cout << result;
  return 0;
}