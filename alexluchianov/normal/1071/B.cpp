#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;
char v[5 + nmax][5 + nmax];
int dp[5 + nmax][5 + nmax];
int seen[5 + nmax][5 + nmax];

struct Square{
  int x , y;
};

bool valid(int x , int y  , int n){
  return (1 <= x && x <= n) && (1 <= y && y <= n);
}

int stx[5 + nmax][5 + nmax];
int sty[5 + nmax][5 + nmax];

void showpath(int x , int y){
  if(1 < x || 1 < y)
    showpath(stx[x][y] , sty[x][y]);
  cout << v[x][y];
}

int main()
{
  int n , k;
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
      cin >> v[i][j];

  if(0 < k && v[1][1] != 'a'){
    k--;
    v[1][1] = 'a';
  }

  dp[1][1] = k;
  seen[1][1] = 1;

  for(int i = 2 ; i <= n ; i++){
    int x = i , y = 1;
    int smin = 'z';

    while(valid(x , y , n)){
      int canuse = 0;
      bool ok = 0;
      if(valid(x - 1 , y , n) && seen[x - 1][y] == 1){

        canuse = MAX(canuse , dp[x - 1][y]);
        smin = MIN(smin , v[x][y]);
      }

      if(valid(x , y - 1, n) && seen[x][y - 1] == 1){

        canuse = MAX(canuse , dp[x][y - 1]);
        smin = MIN(smin , v[x][y]);
      }
      if(0 < canuse)
        smin = 'a';
      x--;
      y++;
    }

    x = i , y = 1;

    while(valid(x , y , n)){
      int canuse = 0;
      bool ok = 0;
      if(valid(x - 1 , y , n) && seen[x - 1][y] == 1) {
        if(canuse <= dp[x - 1][y]) {
          stx[x][y] = x - 1;
          sty[x][y] = y;
        }

        canuse = MAX(canuse , dp[x - 1][y]);
        ok = 1;
      }

      if(valid(x , y - 1, n) && seen[x][y - 1] == 1) {
        if(canuse <= dp[x - 1][y]) {
          stx[x][y] = x;
          sty[x][y] = y - 1;
        }

        canuse = MAX(canuse , dp[x][y - 1]);
        ok = 1;
      }

      dp[x][y] = canuse;
      if(0 < dp[x][y] && v[x][y] != 'a') {
        v[x][y] = 'a';
        dp[x][y]--;
      }

      if(ok == 1 && smin == v[x][y])
        seen[x][y] = 1;
      x--;
      y++;
    }
  }

  for(int j = 2 ; j <= n ; j++){
    int x = n , y = j;
    int smin = 'z';

    while(valid(x , y , n)){
      int canuse = 0;
      bool ok = 0;
      if(valid(x - 1 , y , n) && seen[x - 1][y] == 1){

        canuse = MAX(canuse , dp[x - 1][y]);
        smin = MIN(smin , v[x][y]);
      }

      if(valid(x , y - 1, n) && seen[x][y - 1] == 1){
        canuse = MAX(canuse , dp[x][y - 1]);
        smin = MIN(smin , v[x][y]);
      }
      if(0 < canuse)
        smin = 'a';
      x--;
      y++;
    }

    x = n , y = j;

    while(valid(x , y , n)){
      int canuse = 0;
      bool ok = 0;
      if(valid(x - 1 , y , n) && seen[x - 1][y] == 1) {
        if(canuse <= dp[x - 1][y]) {
          stx[x][y] = x - 1;
          sty[x][y] = y;
        }

        canuse = MAX(canuse , dp[x - 1][y]);
        ok = 1;
      }

      if(valid(x , y - 1, n) && seen[x][y - 1] == 1) {
        if(canuse <= dp[x - 1][y]) {
          stx[x][y] = x;
          sty[x][y] = y - 1;
        }

        canuse = MAX(canuse , dp[x][y - 1]);
        ok = 1;
      }

      dp[x][y] = canuse;
      if(0 < dp[x][y] && v[x][y] != 'a') {
        v[x][y] = 'a';
        dp[x][y]--;
      }

      if(ok == 1 && smin == v[x][y])
        seen[x][y] = 1;
      x--;
      y++;
    }
  }

  showpath(n , n);

  return 0;
}