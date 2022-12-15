#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

int n,m;
vector<pii> adj[100001];
int ind[100001];

bool check(int v) {
    fill(ind+1,ind+n+1,0);
    for(int i=1;i<=n;i++) for(auto &it:adj[i])if(it.se<=v) ind[it.fi]++;
    queue<int> que;
    for(int i=1;i<=n;i++) if(!ind[i]) que.push(i);
    while(!que.empty()) {
        if(que.size()>1) return false;
        int cur=que.front();que.pop();
        for(auto &it:adj[cur]) if(it.se<=v) {
            ind[it.fi]--;
            if(!ind[it.fi])que.push(it.fi);
        }
    }
    return true;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;i++){
        scanf("%d%d",&u,&v);
        adj[u].push_back(pii(v,i));
    }
    int lo=-1,up=m;
    while(up-lo>1) {
        int md=(lo+up)>>1;
        if(check(md)) up=md;
        else lo=md;
    }
    if(up==m) up=-2;
    printf("%d\n",up+1);
    return 0;
}