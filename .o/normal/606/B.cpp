#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,m,x,y;

char s[100500];
int dt[505][505];
int ans[100500];

int main(){
 scanf("%d%d%d%d", &n,&m,&x,&y);
 scanf("%s",s);
 memset(dt,-1,sizeof dt);
 int last = strlen(s); dt[x][y] = 0;
 for(char *c = s; *c != '\0'; c++) {
  if(*c == 'U') --x; if(*c == 'D') ++x;
  if(*c == 'L') --y; if(*c == 'R') ++y;
  if(x < 1) x = 1; if( x > n) x = n; if(y < 1) y = 1; if(y > m) y = m;
  if(dt[x][y] < 0) dt[x][y] = c - s + 1;
 }
 for(int i = 1; i <= n; i++) {
  for(int j = 1; j <= m; j++) {
   if(dt[i][j] < 0) dt[i][j ] = last;
   ans[dt[i][j]]++;
  }
 }
 int l = strlen(s);
 for(int i = 0; i <= l; i++) printf("%d ", ans[i]);
 
}