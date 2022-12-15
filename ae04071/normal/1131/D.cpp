#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2001];
int n,m,pa[2001];
char str[1010][1010];

int vis[2001],in[2001];

int find(int cur) {
    return cur==pa[cur] ? cur : pa[cur]=find(pa[cur]);
}
void merge(int u,int v) {
    u=find(u), v=find(v);
    if(u!=v) pa[v]=u;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    for(int i=0;i<n+m;i++) pa[i] = i;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(str[i][j]=='=') {
        merge(i,n+j);
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(str[i][j]=='>') adj[find(j+n)].push_back(find(i)),in[find(i)]++;
        else if(str[i][j]=='<') adj[find(i)].push_back(find(j+n)),in[find(j+n)]++;
    }
    queue<int> que;
    for(int i=0;i<n+m;i++) if(find(i)==i && !in[i]) {
        vis[i]=1;que.push(i);
    }
    while(!que.empty()) {
        int cur=que.front();que.pop();
        for(auto &it:adj[cur]) {
            in[it]--; vis[it] = max(vis[it], vis[cur]+1);
            if(!in[it]) {
                que.push(it);
            }
        }
    }
    for(int i=0;i<n+m;i++) if(find(i)==i && in[i]) {
        puts("No");
        return 0;
    }
    puts("Yes");
    for(int i=0;i<n;i++) printf("%d ",vis[find(i)]);
    puts("");
    for(int i=n;i<n+m;i++) printf("%d ",vis[find(i)]);

    return 0;
}