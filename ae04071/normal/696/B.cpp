#include <bits/stdc++.h>
using namespace std;

int n,ans[100001];
vector<int> adj[100001];

int dfs(int cur,int d) {
    int s=0;
    for(auto &it:adj[cur]) s+=dfs(it, d+1);
    ans[cur] = (n-s) + d;
    return s+1;
}
int main() {
    scanf("%d",&n);
    for(int i=2;i<=n;i++) {
        int v;
        scanf("%d",&v);
        adj[v].push_back(i);
    }
    dfs(1,1);

    printf("1.0 ");
    for(int i=2;i<=n;i++) printf("%d.%d ",ans[i]/2,ans[i]%2*5);

    return 0;
}