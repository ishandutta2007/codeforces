#include <bits/stdc++.h>
using namespace std;

int t,n;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        
        long long ans = 1ll*n*(n+1)/2;
        for(int i=0;(1ll<<i)<=n;i++) ans -= 1ll<<(i+1);
        printf("%lld\n",ans);
    }
    return 0;
}