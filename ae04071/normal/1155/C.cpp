#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,m;
lli arr[300000];
int main() {
    scanf("%d%d",&n,&m);
    lli g=0;
    for(int i=0;i<n;i++) scanf("%lld",arr+i);
    for(int i=1;i<n;i++) g = __gcd(g,arr[i]-arr[i-1]);

    for(int i=1;i<=m;i++) {
        lli v;
        scanf("%lld",&v);
        if(g%v==0) {
            puts("YES");
            printf("%lld %d\n",arr[0],i);
            return 0;
        }
    }
    puts("NO");
    
    return 0;
}