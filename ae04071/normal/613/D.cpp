#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;

int n,ea[17][100001],dl[100001],dr[100001],dn,de[100001];
vector<int> adj[100001];

void dfs(int cur,int p,int d) {
    int pp=p,a=1;
    ea[0][cur] = p;
    while(ea[a-1][pp]) {
        pp=ea[a][cur] = ea[a-1][pp];
        a++;
    }
    de[cur]=d;
    dl[cur]=++dn;
    for(auto &it:adj[cur])if(it!=p) {
        dfs(it,cur,d+1);
    }
    dr[cur]=dn;
}
int lca(int u,int v) {
    if(de[u]>de[v])swap(u,v);
    int dif=de[v]-de[u];
    for(int i=0;1<<i<=dif;i++) if(dif>>i&1) {
        v=ea[i][v];
    }
    if(u==v) return u;
    for(int i=16;i>=0;i--) if(ea[i][u]!=ea[i][v]){
        u=ea[i][u]; v=ea[i][v];
    }
    return ea[0][v];
}

int solve(vector<int> arr) {
    sort(arr.begin(),arr.end(),[&](const int &a,const int &b) {
        return dl[a] < dl[b];
    });
    stack<pii> stk;
    for(int i=0;i<sz(arr);i++) {
        while(!stk.empty() && stk.top().first < dl[arr[i]]) stk.pop();
        if(!stk.empty() && stk.top().second == ea[0][arr[i]]) return -1;
        stk.push({dr[arr[i]],arr[i]});
    }

    set<int> idx;
    set<pii> val;
    int ret=0;
    for(int i=0;i<sz(arr);i++) idx.insert(i);
    for(int i=0;i<sz(arr)-1;i++) val.insert({-de[lca(arr[i],arr[i+1])],i});
    while(!val.empty()) {
        int i=val.begin()->second,d=-val.begin()->first;
        auto it=idx.find(i);
        val.erase(val.begin());
        
        if(d==de[arr[i]]) {
            auto jt=next(it);
            if(next(jt)!=idx.end()) {
                auto kt=next(jt);
                val.erase({-de[lca(arr[*jt],arr[*kt])],*jt});
            }
            idx.erase(jt);
            it++;
            if(it!=idx.end()) val.insert({-de[lca(arr[i],arr[*it])],i});
        } else {
            if(it!=idx.begin()) {
                auto jt=prev(it);
                val.erase({-de[lca(arr[*jt], arr[*it])],*jt});
            }
            it=idx.erase(it);
            while(it!=idx.end()) {
                auto jt=next(it);
                if(jt==idx.end()) break;
                
                int p=lca(arr[*it],arr[*jt]);
                val.erase({-de[p],*it});
                if(de[p]!=d) break;
                it=idx.erase(it);
            }
            it=idx.erase(it);
            if(it!=idx.end() && it!=idx.begin()) {
                auto jt=prev(it);
                val.insert({-de[lca(arr[*jt],arr[*it])], *jt});
            }
        }
        ret++;
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  
    dfs(1,0,0);
    int q;
    scanf("%d",&q);
    while(q--) {
        int s;
        vector<int> arr;
        scanf("%d",&s);
        while(s--) {
            int v;
            scanf("%d",&v);
            arr.push_back(v);
        }
        printf("%d\n",solve(arr));
    }
    
    return 0;
}