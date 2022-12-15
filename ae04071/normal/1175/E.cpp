#include <bits/stdc++.h>
using namespace std;

int nxt[18][500011],n,m;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        nxt[0][l]=max(nxt[0][l],r);
    }

    for(int i=1;i<500000;i++) {
        nxt[0][i] = max({nxt[0][i], i, nxt[0][i-1]});
    }
    for(int i=0;i<18;i++) nxt[i][500000]=500000;

    for(int i=1;i<18;i++) {
        for(int j=0;j<500000;j++) {
            nxt[i][j] = nxt[i-1][nxt[i-1][j]];
        }
    }

    for(int i=0;i<m;i++) {
        int l,r,ans=0;
        scanf("%d%d",&l,&r);
        for(int i=17;i>=0;i--) {
            if(nxt[i][l]<r) {
                ans += 1<<i;
                l = nxt[i][l];
            }
        }
        if(nxt[0][l]>=r) printf("%d\n",ans+1);
        else puts("-1");
    }
    
    return 0;
}