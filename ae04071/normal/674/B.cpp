#include <bits/stdc++.h>
using namespace std;

int n,m,vis[1001],a,b,c,d;
int main() {
    scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
    if(n<=4 || m<=n) {
        puts("-1");
        return 0;
    }
    vis[a]=vis[b]=vis[c]=vis[d]=1;
    
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(c);
    for(int i=1;i<=n;i++) if(!vis[i]) ans.push_back(i);
    ans.push_back(d);
    ans.push_back(b);

    for(auto &it:ans) printf("%d ",it);
    puts("");
    printf("%d %d ",c,a);
    for(int i=2;i<n-2;i++) printf("%d ",ans[i]);
    printf("%d %d\n",b,d);
    
    return 0;
}