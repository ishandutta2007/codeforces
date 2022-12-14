#include<bits/stdc++.h>
using namespace std;

char a[205000],b[205000];int n,m;
int main() {
 scanf("%s",a+1);n=strlen(a+1);
 scanf("%s",b+1);m=strlen(b+1);b[0]='0';
 int s=0; long long ans = 0;
 for(int k = 1; k <= m-n; k++) s += b[k]-'0';
 for(int i = 1, j = m-n+1; i <= n; i++, j++) {
  s -= b[i-1]-'0';
  s += b[j]-'0';
  ans += (a[i] == '0') ? s : ((m-n+1) - s);
 }
 ////
 printf("%I64d\n", ans);
 return 0;
}