#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b,c,d,ans=0;
    scanf("%d",&n);
    a=0;b=0;
    for(int i=0;i<n;i++,a=c,b=d) {
        scanf("%d%d",&c,&d);
        if(a>d || b>c) continue;
        
        if(i!=0 && a==b) ans-=1;
        ans += min(c,d) - max(a,b)+1;
    }
    printf("%d\n",ans);
}