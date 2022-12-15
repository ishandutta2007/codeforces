#include <bits/stdc++.h>
using namespace std;

int n,a[200001],vis[200001];
vector<int> cand;

void dfs(int cur) {
    if(vis[cur]==1) {
        cand.push_back(cur);
    } else if(!vis[cur]) {
        vis[cur] = 1;
        dfs(a[cur]);
        vis[cur] = 2;
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);

    int r = -1, ans = 0;
    for(auto &it:cand) if(a[it]==it) {
        r=it; break;
    }
    if(r==-1) {
        r = cand[0]; a[cand[0]] = r;
        for(int i=1;i<cand.size();i++) a[cand[i]] = r;
        ans = cand.size();
    } else {
        ans = cand.size() - 1;
        for(auto &v:cand) if(r!=v) a[v] = r;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);

    return 0;
}