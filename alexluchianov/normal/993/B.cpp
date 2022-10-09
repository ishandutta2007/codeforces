#include <iostream>

using namespace std;
int const nmax = 20;

int v[5 + nmax][2];
int v2[5 + nmax][2];

int valid(int x , int y){
  if(v[x][0] == v2[y][0] && v[x][1] == v2[y][1]){
    return 0;
  } else if(v[x][0] == v2[y][0])
    return v[x][0];
  else if(v[x][1] == v2[y][1])
    return v[x][1];
  else if(v[x][0] == v2[y][1])
    return v[x][0];
  else if(v[x][1] == v2[y][0])
    return v[x][1];
  else
    return 0;
}

int main()
{
  int n , m;
  cin >> n >> m;
  for(int i = 1 ; i <= n ;i++){
    cin >> v[i][0] >> v[i][1];
    if(v[i][1] < v[i][0])
      swap(v[i][1] , v[i][0]);
  }
  for(int i = 1 ; i <= m ;i++){
    cin >> v2[i][0] >> v2[i][1];
    if(v2[i][1] < v2[i][0])
      swap(v2[i][1] , v2[i][0]);
  }

  int validpairs = 0;
  int lastpair = 0;
  bool ok = 1;

  for(int i = 1 ; i <= n ;i++){
    int pars = 0;

    for(int j = 1 ; j <= m ;j++){
      if(0 < valid(i , j)){
        if(0 < lastpair && lastpair != valid(i , j)){
          ok = 0;
        } else
          lastpair = valid(i , j);

        if(0 < pars && pars != valid(i , j)){
          cout << -1;
          return 0;
        } else
          pars = valid(i , j);
      }
    }
  }
  if(ok == 1){
    cout << lastpair << '\n';
    return 0;
  }

  for(int j = 1 ; j <= m ;j++){
    int pars = 0;
    for(int i = 1 ; i <= n ;i++){
      if(0 < valid(i , j)){
        if(0 < pars && pars != valid(i , j)){
          cout << -1;
          return 0;
        } else
          pars = valid(i , j);
      }
    }
  }
  cout << 0 << '\n';
  return 0;
}