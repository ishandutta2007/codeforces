#include<bits/stdc++.h>
using namespace std;

int n,s,a[10000];
int main() {
 scanf("%d%d",&n,&s);
 while(n--) {
  int f,t;scanf("%d%d",&f,&t);
  a[f] = max(a[f], t);/////
 }
 int ans = 0;
 for(int f = s; f > 0; f--) {
  ans = max(ans, a[f]);
  ans++;
 }
 printf("%d\n", ans);
 return 0;
}