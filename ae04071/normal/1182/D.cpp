#include <bits/stdc++.h>
using namespace std;

int n,dp[100001][2];
vector<int> adj[100001];

int dfs(int cur,int p) {
    for(auto &it:adj[cur]) if(it!=p) {
        int v=dfs(it,cur);
        if(dp[cur][0] < v) {
            dp[cur][1] = dp[cur][0];
            dp[cur][0] = v;
        } else if(dp[cur][1] < v) {
            dp[cur][1] = v;
        }
    }
    return dp[cur][0]+1;
}

int md,mr,cv;
void cal(int cur,int p,int d) {
    int d1=dp[cur][0],d2=dp[cur][1];
    if(d1<d) swap(d,d1);
    if(d2<d) swap(d2,d);
    
    md=max(md,d1+d2);
    if(md==d1+d2 && d2==0) mr=cur;
    if(md==d1+d2 && d1==d2) cv=cur;
    for(auto &it:adj[cur]) if(it!=p) {
        if(dp[it][0]+1==d1) cal(it,cur,d2+1);
        else cal(it,cur,d1+1);
    }
}
int find_other(int cur,int p,int d) {
    if(d==md) return cur;
    for(auto &it:adj[cur]) if(it!=p) {
        int v=find_other(it,cur,d+1);
        if(v!=0) return v;
    }
    return 0;
}

int ga[100001],sz[100001],lv[100001],mv[100001],tr;
bool f;
void check(int cur,int p,int d) {
    if(!ga[d]) ga[d] = (int)adj[cur].size();
    else if(ga[d]!=(int)adj[cur].size()) f=false;
    
    int cf=0;
    mv[cur] = n+1; sz[cur] = lv[cur] = 0;
    for(auto &it:adj[cur]) if(it!=p) {
        check(it,cur,d+1);
        sz[cur] += sz[it];
        if(sz[it]==1) {
            if(mv[cur] > mv[it]) {
                mv[cur] = mv[it];
                lv[cur] = lv[it];
            }
        }
        cf=1;
    }
    if(!cf) {
        sz[cur]=1; lv[cur]=cur; mv[cur]=d;
    }
}

bool proc(int cur) {
    fill(ga,ga+n+1,0);
    f=true;
    check(cur,0,0);
    if(f)printf("%d\n",cur);
    return f;
}

int main() {
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cal(1,0,0);

    int m1=mr,m2=find_other(mr,0,0);
    
    if(proc(m1)) return 0;
    if(proc(m2)) return 0;
    if(md%2==0) {
        if(proc(cv)) return 0;
        if(lv[cv]!=0 && proc(lv[cv])) return 0;
    }
    puts("-1");
    
    return 0;
}