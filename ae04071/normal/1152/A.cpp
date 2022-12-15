#include <bits/stdc++.h>
using namespace std;

int n,m;
int main() {
    scanf("%d%d",&n,&m);
    
    int a[2]={0,},ans=0;
    for(int i=0;i<n;i++) {
        int v;
        scanf("%d",&v);
        a[v%2]++;
    }
    for(int i=0;i<m;i++) {
        int v;
        scanf("%d",&v);
        v=(v%2)^1;
        if(a[v]) a[v]--,ans++;
    }
    printf("%d\n",ans);
    return 0;
}