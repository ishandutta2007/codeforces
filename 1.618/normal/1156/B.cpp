#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int cnt[35],T;
char s[105];
void print(int x){
  for(int i = 1;i <= cnt[x];i++) putchar(char(x + 'a'));
}
void solve(){
  memset(cnt,0,sizeof(cnt));
  scanf("%s",s);
  for(int i = 0;i < (int)strlen(s);i++) cnt[s[i] - 'a']++;
  vector <int> app;
  for(int i = 0;i < 26;i++){
    if(cnt[i]) app.push_back(i);
  }
  int tot = app.size();
  if(tot == 1){
    print(app[0]);
    printf("\n");
    return;
  }
  if(tot == 2){
    if(app[1] - app[0] == 1){
      puts("No answer");
      return;
    }
    print(app[0]);
    print(app[1]);
    printf("\n");
    return;
  }
  if(tot == 3){
    if(app[2] - app[0] == 2){
      puts("No answer");
      return;
    }
    if(app[1] - app[0] == 1){
      print(app[0]);
      print(app[2]);
      print(app[1]);
    }else{
      print(app[1]);
      print(app[0]);
      print(app[2]);
    }
    printf("\n");
    return;
  }
  if(tot == 4){
    print(app[2]);
    print(app[0]);
    print(app[3]);
    print(app[1]);
    printf("\n");
    return;
  }
  for(int i = 0;i < tot;i += 2) print(app[i]);
  for(int i = 1;i < tot;i += 2) print(app[i]);
  printf("\n");
}
int main(){
  T = getint();
  while(T--) solve();
  return 0;
}