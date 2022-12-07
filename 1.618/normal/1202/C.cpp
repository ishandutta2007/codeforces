#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 200005

using namespace std;
typedef long long ll;

int T,n,minx,maxx,miny,maxy,cx,cy,x,y;
char s[maxn];
//WASD
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
int dir[305];
int main(){
  dir['W'] = 0, dir['A'] = 1, dir['S'] = 2, dir['D'] = 3;
  scanf("%d",&T);
  while(T--){
    scanf("%s",s + 1);
    cx = cy = minx = maxx = miny = maxy = 0;
    n = strlen(s + 1);
    for(int i = 1;i <= n;i++){
      cx += dx[dir[s[i]]];
      cy += dy[dir[s[i]]];
      minx = min(minx,cx);
      maxx = max(maxx,cx);
      miny = min(miny,cy);
      maxy = max(maxy,cy);
    }
    x = maxx - minx + 1;
    y = maxy - miny + 1;
    cx = cy = 0;
    vector <int> xs,ys;
    if(cx == maxx) xs.push_back(1);
    if(cx == minx) xs.push_back(-1);
    if(cy == maxy) ys.push_back(1);
    if(cy == miny) ys.push_back(-1);
    for(int i = 1;i <= n;i++){
      cx += dx[dir[s[i]]];
      cy += dy[dir[s[i]]];
      if(cx == maxx) xs.push_back(1);
      if(cx == minx) xs.push_back(-1);
      if(cy == maxy) ys.push_back(1);
      if(cy == miny) ys.push_back(-1);
    }
    bool okx = true, oky = true;
    for(int i = 0;i < (int)xs.size();i++){
      if(xs[i] != xs[0]){
        for(int j = i + 1;j < (int)xs.size();j++){
          if(xs[j] == xs[0]){
            okx = false;
            break;
          }
        }
        break;
      }
    }
    for(int i = 0;i < (int)ys.size();i++){
      if(ys[i] != ys[0]){
        for(int j = i + 1;j < (int)ys.size();j++){
          if(ys[j] == ys[0]){
            oky = false;
            break;
          }
        }
        break;
      }
    }
    if(x > y) swap(x,y), swap(okx,oky);
    if(x > 2 && okx) printf("%I64d\n",ll(x - 1) * y);
    else if(y > 2 && oky) printf("%I64d\n",ll(y - 1) * x);
    else printf("%I64d\n",(ll)x * y);
  }
  return 0;
}