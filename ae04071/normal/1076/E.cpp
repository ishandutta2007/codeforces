#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int n;
vector<int> adj[300001];
map<int,lli> cost[300001];

set<pll> tr;
lli ans[300001];

lli sum=0;
void add(lli idx,lli val){
    auto it=tr.lower_bound(pll(idx,0));
    if(it==tr.end()||it->fi!=idx){
        tr.insert(pll(idx,val));
    }else{
        tr.insert(pll(idx,val+it->se));
        tr.erase(it);
    }
    sum+=val;
}
void sub(lli idx,lli val){
    auto it=tr.lower_bound(pll(idx,0));
    if(val!=it->se) tr.insert(pll(idx,it->se-val));
    tr.erase(it);
    sum-=val;
}
void dfs(int cur,int p,int d){
    for(auto &v:cost[cur]) {
        add(d+v.fi,v.se);
    }
    ans[cur]=sum;

    lli t=-1;
    if(!tr.empty()&&tr.begin()->fi==d){
        t=tr.begin()->se;
        sum-=t;
        tr.erase(tr.begin());
    }

    for(auto &it:adj[cur])if(it!=p){
        dfs(it,cur,d+1);
    }
    if(t!=-1) tr.insert(pll(d,t)),sum+=t;
    for(auto &v:cost[cur]) sub(d+v.fi,v.se);
}
int main(){
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int v,d,x;
        scanf("%d%d%d",&v,&d,&x);
        cost[v][d]+=x;
    }

    dfs(1,0,0);
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);

    return 0;
}