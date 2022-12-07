#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#define maxn 25

using namespace std;
typedef long long ll;

int n,m,w,sg[maxn][maxn][maxn][maxn];
char a[maxn][maxn],field[maxn][maxn];
int calc(int r1,int c1,int r2,int c2){
  if(r1 > r2 || c1 > c2) return 0;
  if(~sg[r1][c1][r2][c2]) return sg[r1][c1][r2][c2];
  vector <int> b;
  for(int i = r1;i <= r2;i++){
    for(int j = c1;j <= c2;j++){
      if(a[i][j] == 'L'){
        b.push_back(calc(r1,c1,i - 1,c2) ^ calc(i + 1,c1,r2,c2));
      }else if(a[i][j] == 'R'){
        b.push_back(calc(r1,c1,r2,j - 1) ^ calc(r1,j + 1,r2,c2));
      }else if(a[i][j] == 'X'){
        b.push_back(calc(r1,c1,i - 1,j - 1) ^ calc(r1,j + 1,i - 1,c2)
                    ^ calc(i + 1,c1,r2,j - 1) ^ calc(i + 1,j + 1,r2,c2));
      }
    }
  }
  sort(b.begin(),b.end());
  b.erase(unique(b.begin(),b.end()),b.end());
  int res = 0;
  while(res < (int)b.size() && b[res] == res) res++;
  return sg[r1][c1][r2][c2] = res;
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i = 1;i <= n;i++) scanf("%s",field[i] + 1);
  memset(sg,-1,sizeof(sg));
//  memset(a,0,sizeof(a));
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if(!((i + j) & 1))
        a[(i + j) >> 1][(n - i + j + 1) >> 1] = field[i][j];
    }
  }
  int res = calc(1,1,(n + m) >> 1,(n + m) >> 1);
  memset(sg,-1,sizeof(sg));
  memset(a,0,sizeof(a));
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if((i + j) & 1)
        a[(i + j) >> 1][(n - i + j + 1) >> 1] = field[i][j];
    }
  }
  res ^= calc(1,1,(n + m) >> 1,(n + m) >> 1);
  puts(res ? "WIN" : "LOSE");
  return 0;
}