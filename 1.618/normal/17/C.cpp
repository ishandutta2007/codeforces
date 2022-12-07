#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#define maxn 155

using namespace std;
typedef long long ll;
const int mod = 51123987;

int n,m,f[maxn][55][55][55],pos[3];
char S[maxn],t[maxn];
int main(){
  scanf("%d",&n);
  scanf("%s",S + 1);
  for(int i = 1;i <= n;i++) if(S[i] != S[i - 1]) t[++m] = S[i];
  f[0][0][0][0] = 1;
  for(int i = 1;i <= m;i++){
    for(int x = 0;x <= 50;x++){
      for(int y = 0;y <= 50;y++){
        for(int z = 0;z <= 50;z++){
          if(t[i] == 'a'){
            if(!x) continue;
            f[i][x][y][z] = f[i][x - 1][y][z];
            if(pos[1]) (f[i][x][y][z] += f[pos[1]][x - 1][y][z]) %= mod;
            if(pos[2]) (f[i][x][y][z] += f[pos[2]][x - 1][y][z]) %= mod;
            (f[i][x][y][z] += (x == 1) && !y && !z) %= mod;
          }else if(t[i] == 'b'){
            if(!y) continue;
            f[i][x][y][z] = f[i][x][y - 1][z];
            if(pos[0]) (f[i][x][y][z] += f[pos[0]][x][y - 1][z]) %= mod;
            if(pos[2]) (f[i][x][y][z] += f[pos[2]][x][y - 1][z]) %= mod;
            (f[i][x][y][z] += !x && (y == 1) && !z) %= mod;
          }else{
            if(!z) continue;
            f[i][x][y][z] = f[i][x][y][z - 1];
            if(pos[0]) (f[i][x][y][z] += f[pos[0]][x][y][z - 1]) %= mod;
            if(pos[1]) (f[i][x][y][z] += f[pos[1]][x][y][z - 1]) %= mod;
            (f[i][x][y][z] += !x && !y && (z == 1)) %= mod;
          }
        }
      }
    }
    pos[t[i] - 'a'] = i;
  }
  int k = n / 3, ans = 0;
  for(int i = 0;i < 3;i++){
    if(n % 3 == 0) (ans += f[pos[i]][k][k][k]) %= mod;
    else if(n % 3 == 1){
      (ans += f[pos[i]][k + 1][k][k]) %= mod;
      (ans += f[pos[i]][k][k + 1][k]) %= mod;
      (ans += f[pos[i]][k][k][k + 1]) %= mod;
    }else{
      (ans += f[pos[i]][k + 1][k + 1][k]) %= mod;
      (ans += f[pos[i]][k + 1][k][k + 1]) %= mod;
      (ans += f[pos[i]][k][k + 1][k + 1]) %= mod;
    }
  }
  printf("%d\n",ans);
  return 0;
}