#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        lli n,k;
        scanf("%lld%lld",&n,&k);
        
        lli ans=0;
        while(n) {
            ans+=n%k;
            n-= n%k;
            if(n!=0) n/=k,ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}