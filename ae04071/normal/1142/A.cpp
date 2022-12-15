#include <bits/stdc++.h>
using namespace std;

int vis[100001];
int main() {
    int n,k,a,b;
    scanf("%d%d%d%d",&n,&k,&a,&b);

    long long x=1e15,y=0;
    for(int s=0;s<k;s++) if(min(s,k-s)==a) {
        for(int l=1;l<=k;l++) if(min((s+l)%k, k-(s+l)%k)==b) {
            for(int i=0;i<n;i++) {
                x = min(x,1ll*n*k/__gcd(1ll*n*k,l+1ll*i*k));
                y = max(y,1ll*n*k/__gcd(1ll*n*k,l+1ll*i*k));
            }
        }
    }
    printf("%lld %lld\n",x,y);
    return 0;
}