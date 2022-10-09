#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int const nmax = 50;
int const iplus[4] = {0 , 0 , 1 , -1};
int const jplus[4] = {1 , -1 , 0 , 0};

struct Lake{
  int x ;
  int y;
  int sz;
  bool operator < (Lake const &a) const{
    return sz < a.sz;
  }
};
char v[5 + nmax][5 + nmax];
int seen[5 + nmax][5 + nmax];

vector < Lake > lakes;

int n , m;

void flood(int x , int y){
  lakes.push_back({x , y, 1});
  queue<Lake> q;
  q.push({x , y , 0});
  bool ok = 1;
  seen[x][y] = 1;
  if(x == n || x == 1 || y == 1 || y == m)
    ok = 0;

  while(0 < q.size()){
    x = q.front().x;
    y = q.front().y;
    q.pop();
    for(int h = 0 ; h < 4 ;h++){
      int newx = x + iplus[h];
      int newy = y + jplus[h];
      if(v[newx][newy] == '.' && seen[newx][newy] == 0){
        seen[newx][newy] = 1;
        if(newx == n || newx == 1 || newy == 1 || newy == m)
          ok = 0;
        q.push({newx , newy , 0});
        lakes.back().sz++;
      }
    }
  }
  if(ok == 0)
    lakes.pop_back();
}
void floodearth(int x , int y){
  queue<Lake> q;
  v[x][y] = '*';
  q.push({x , y , 0});
  while(0 < q.size()){
    x = q.front().x;
    y = q.front().y;
    q.pop();
    for(int h = 0 ; h < 4 ;h++){
      int newx = x + iplus[h];
      int newy = y + jplus[h];
      if(v[newx][newy] == '.'){
        v[newx][newy] = '*';
        q.push({newx , newy , 0});
      }
    }
  }
}

int main()
{
  int k;
  cin >> n >> m >> k;
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= m ; j++)
      cin >> v[i][j];
  for(int i = 1; i <= n ; i++)
    for(int j = 1 ;j <= m ; j++)
      if(v[i][j] == '.' && seen[i][j] == 0)
        flood(i , j);
  sort(lakes.begin() , lakes.end());

  int sum = 0;
  for(int i = 0 ; i < lakes.size() - k ; i++){
    floodearth(lakes[i].x ,lakes[i].y);
    sum += lakes[i].sz;
  }
  cout << sum << '\n';
  for(int i = 1 ; i <= n ; i++) {
    for(int j = 1 ; j <= m ; j++)
      cout << v[i][j];
    cout << '\n';
  }
  return 0;
}