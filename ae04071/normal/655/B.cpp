#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    
    long long ans=0;
    for(int i=0;i<min(n/2,k);i++) ans += n-1-2*i + n-2-2*i;
    printf("%lld\n",ans);

    return 0;
}