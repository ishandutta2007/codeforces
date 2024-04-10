#include<bits/stdc++.h>
using namespace std;

int n,c[505],tb[505][505];
int main() {
 scanf("%d", &n);
 for(int i=1; i<=n; i++) scanf("%d", c+i);
 for(int i =1; i<=n; i++) tb[i][i] = 1;
 for(int x = 1; x < n; x++) {
  for(int i = 1, j = 1+x; j <= n; i++, j++) {
   tb[i][j] = (int)1e9;
   if(c[i] == c[j]) tb[i][j] = (x == 1) ? 1 :tb[i+1][j-1];
   for(int k = i; k < j; k++) tb[i][j] = min(tb[i][j], tb[i][k] + tb[k+1][j]);
  }///
 }///////////////
 printf("%d\n", tb[1][n]);
 return 0;
}