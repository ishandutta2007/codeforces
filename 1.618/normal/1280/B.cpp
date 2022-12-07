#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 65

using namespace std;
typedef long long ll;

int t,r,c,sumrow[maxn],sumcol[maxn];
char s[maxn][maxn];

void solve(){
  memset(sumrow,0,sizeof(sumrow));
  memset(sumcol,0,sizeof(sumcol));
  int tot = 0;
  bool ok1 = false, ok2 = false, ok3 = false;
  for(int i = 1;i <= r;i++){
    for(int j = 1;j <= c;j++){
      if(s[i][j] == 'P') continue;
      sumrow[i]++;
      sumcol[j]++;
      tot++;
      if(sumrow[i] == c){
        if(i == 1 || i == r) ok1 = true;
        ok2 = true;
      }
      if(sumcol[j] == r){
        if(j == 1 || j == c) ok1 = true;
        ok2 = true;
      }
      ok3 |= (i == 1) || (i == r) || (j == 1) || (j == c);
    }
  }
  if(tot == 0){
    puts("MORTAL");
    return;
  }
  if(tot == r * c){
    puts("0");
    return;
  }
  if(ok1){
    puts("1");
    return;
  }
  ok2 |= (s[1][1] == 'A') || (s[1][c] == 'A') ||
         (s[r][1] == 'A') || (s[r][c] == 'A');
  if(ok2){
    puts("2");
    return;
  }
  if(ok3){
    puts("3");
    return;
  }
  puts("4");
}
int main(){
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&r,&c);
    for(int i = 1;i <= r;i++) scanf("%s",s[i] + 1);
    solve();
  }
  return 0;
}