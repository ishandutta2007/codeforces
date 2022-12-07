#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 2005
#define mod 1000000007

using namespace std;
typedef long long ll;

int n,m;
int f[maxn][maxn][2],s[maxn][maxn][2],rock[maxn][maxn][2];
char grid[maxn][maxn];
int main(){
  scanf("%d%d",&n,&m);
  for(int i = 1;i <= n;i++) scanf("%s",grid[i] + 1);
  if(n == 1 && m == 1){
    puts("1");
    return 0;
  }
  bool ok = true;
  for(int i = n;i >= 1;i--){
    s[i][m][0] = f[i][m][1] = ok;
    ok &= (grid[i][m] == '.');
  }
  ok = true;
  for(int i = m;i >= 1;i--){
    s[n][i][1] = f[n][i][0] = ok;
    ok &= (grid[n][i] == '.');
  }
//  for(int i = 1;i <= n;i++){
//    for(int j = 1;j <= m;j++){
//      cout << f[i][j][0] << " ";
//    }
//    cout << endl;
//  }
//  system("pause");
//  for(int i = 1;i <= n;i++){
//    for(int j = 1;j <= m;j++){
//      cout << f[i][j][1] << " ";
//    }
//    cout << endl;
//  }
//  system("pause");
  for(int i = 1;i < n;i++){
    for(int j = m - 1;j >= 1;j--){
      rock[i][j][0] = rock[i][j + 1][0] + (grid[i][j + 1] == 'R');
    }
  }
  for(int j = 1;j < m;j++){
    for(int i = n - 1;i >= 1;i--){
      rock[i][j][1] = rock[i + 1][j][1] + (grid[i + 1][j] == 'R');
    }
  }
  for(int i = n - 1;i >= 1;i--){
    for(int j = m - 1;j >= 1;j--){
      f[i][j][0] = (s[i][j + 1][0] - s[i][m - rock[i][j][0] + 1][0] + mod) % mod;
      s[i][j][1] = (s[i + 1][j][1] + f[i][j][0]) % mod;
      f[i][j][1] = (s[i + 1][j][1] - s[n - rock[i][j][1] + 1][j][1] + mod) % mod;
      s[i][j][0] = (s[i][j + 1][0] + f[i][j][1]) % mod;
    }
  }
  printf("%d\n",(f[1][1][0] + f[1][1][1]) % mod);
  return 0;
}