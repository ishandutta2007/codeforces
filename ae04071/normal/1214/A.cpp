#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    c *= 5;
    
    int ans=a;
    for(int i=0;i*c<=a;i++) {
        ans = min(ans, (a-i*c)%b);
    }
    printf("%d\n",ans);
    return 0;
}