#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,n;
int main(){
  scanf("%d",&t);
  while(t--){
    scanf("%d%d%d%d",&a,&b,&c,&n);
    int tot = a + b + c + n;
    if(tot % 3) puts("NO");
    else{
      tot /= 3;
      if(a > tot || b > tot || c > tot) puts("NO");
      else puts("YES");
    }
  }
  return 0;
}