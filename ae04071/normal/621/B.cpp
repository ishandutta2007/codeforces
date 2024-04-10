#include <bits/stdc++.h>
using namespace std;

int c1[2001],c2[2001];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        c1[x-y+1000]++;
        c2[x+y]++;
    }

    long long ans=0;
    for(int i=0;i<=2000;i++) {
        ans+=1ll*c1[i]*(c1[i]-1)/2 + 1ll*c2[i]*(c2[i]-1)/2;
    }
    printf("%lld\n",ans);

    return 0;
}