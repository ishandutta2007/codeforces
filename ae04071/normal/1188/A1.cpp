#include <bits/stdc++.h>
using namespace std;

int n,sz[100001];
int main() {
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        sz[u]++;
        sz[v]++;
    }
    for(int i=1;i<=n;i++) if(sz[i]==2) {
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}