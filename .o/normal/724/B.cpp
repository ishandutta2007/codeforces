#include<stdio.h>
#include<algorithm>
int a[100][100];

int main() {
 int n, m; scanf("%d%d", &n, &m);
 for(int j=1;j<=n;j++){
  for(int i =1;i<=m;i++) {
   scanf("%d", &a[j][i]);
  }
 }

 for(int x=1;x<=m;x++) for(int y=x;y<=m;y++) {
  for(int i=1;i<=n;i++) std::swap(a[i][x],a[i][y]);
  bool good = true;
  for(int i=1;i<=n;i++) { int c=0; for(int j=1;j<=m;j++) if(a[i][j]!=j)c++; if(c != 0 && c != 2) good = false; }
  if(good) return 0 & puts("YES");
  for(int i=1;i<=n;i++) std::swap(a[i][x],a[i][y]);
 }
 puts("NO");
 return 0;
}