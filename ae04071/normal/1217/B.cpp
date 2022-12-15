#include <bits/stdc++.h>
using namespace std;

int main() {
    int test,n,x,d,h;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d",&n,&x);
        
        int mx = -1, cg = -1;
        for(int i=0;i<n;i++) {
            scanf("%d%d",&d,&h);
            mx = max(mx, d);
            cg = max(cg, d-h);
        }
        if(mx >= x) {
            puts("1");
        } else if(cg<=0) {
            puts("-1");
        } else {
            printf("%d\n",(x-mx+cg-1)/cg + 1);
        }
    }
    return 0;
}