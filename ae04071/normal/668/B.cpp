#include <bits/stdc++.h>
using namespace std;

int n,m,ta[2000000],va[2000000];
int ans[1000000];

void proc(int s,int v) {
    for(int i=0;i<m;i++) {
        if(ta[i]==1) {
            s = (s+va[i]+n)%n;
        } else {
            s^=1;
        }
    }
    for(int i=0;i<n;i+=2) ans[(s+i)%n] = v+i;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d",ta+i);
        if(ta[i]==1) scanf("%d",va+i);
    }

    proc(0,0);
    proc(1,1);
    for(int i=0;i<n;i++) printf("%d ",ans[i]+1);
    
    return 0;
}