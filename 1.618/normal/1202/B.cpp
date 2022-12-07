#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 2000005

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;

int dis[15][15],n;
char s[maxn];
int solve(int x,int y){
  memset(dis,0x3f,sizeof(dis));
  for(int i = 0;i < 10;i++){
    dis[i][(i + x) % 10] = 1;
    dis[i][(i + y) % 10] = 1;
  }
  for(int k = 0;k < 10;k++){
    for(int i = 0;i < 10;i++){
      for(int j = 0;j < 10;j++){
        dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
      }
    }
  }
  int ans = 0;
  for(int i = 2;i <= n;i++){
    if(dis[s[i - 1] - '0'][s[i] - '0'] == inf) return -1;
    ans += dis[s[i - 1] - '0'][s[i] - '0'] - 1;
  }
  return ans;
}
int main(){
  scanf("%s",s + 1);
  n = strlen(s + 1);
  for(int x = 0;x < 10;x++){
    for(int y = 0;y < 10;y++){
      printf("%d%c",solve(x,y),y == 9 ? '\n' : ' ');
    }
  }
  return 0;
}