#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int const nmax = 100000;
struct Queen{
  int x;
  int y;
  int id;
  bool operator < (Queen const &a) const{
    if(x != a.x)
      return x < a.x;
    else
      return y < a.y;
  }
} v[1 + nmax];
int sol[1 + nmax];
map<int,int> lin, col, diag, diag2;
int realsol[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    cin >> v[i].x >> v[i].y;
    v[i].id = i;
  }
  sort(v + 1, v + m + 1);
  for(int i = 1;i <= m;i++){
    sol[v[i].id] += lin[v[i].x] + col[v[i].y] + diag[v[i].x + v[i].y] + diag2[v[i].x - v[i].y];
    lin[v[i].x] = 1;
    col[v[i].y] = 1;
    diag[v[i].x + v[i].y] = 1;
    diag2[v[i].x - v[i].y] = 1;
  }
  lin.clear();
  col.clear();
  diag.clear();
  diag2.clear();
  reverse(v + 1, v + m + 1);
  for(int i = 1;i <= m;i++){
    sol[v[i].id] += lin[v[i].x] + col[v[i].y] + diag[v[i].x + v[i].y] + diag2[v[i].x - v[i].y];
    lin[v[i].x] = 1;
    col[v[i].y] = 1;
    diag[v[i].x + v[i].y] = 1;
    diag2[v[i].x - v[i].y] = 1;
  }
  for(int i = 1;i <= m; i++)
    realsol[sol[i]] ++;
  for(int i = 0; i <= 8; i++)
    cout << realsol[i] << " ";
  return 0;
}