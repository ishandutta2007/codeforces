#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int,int>;

int n,m,q,ord[200001],a[200001];
vector<int> pos[200001],adj[200001];

int ea[20][200001],de[200001],ind[200001];
char ans[200010];
void make_dfs(int cur,int p,int d) {
    de[cur] = d;
    ea[0][cur] = p;
    int a=1;
    while(p!=-1 && ea[a-1][p]!=-1) {
        p=ea[a][cur]=ea[a-1][p];
        a++;
    }
    for(auto &v:adj[cur]) make_dfs(v,cur,d+1);
}
int get_ep(int u,int dif) {
    for(int i=0;1<<i<=dif;i++) if(dif>>i&1) u=ea[i][u];
    return u;
}

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0,v;i<n;i++) {
        scanf("%d",&v); ord[v-1]=i;
    }
    memset(ea,-1,sizeof(ea));
    for(int i=0;i<m;i++) {
        scanf("%d",a+i);
        a[i]--;
        
        int pr=(ord[a[i]]-1+n)%n;
        while(!pos[pr].empty()) {
            int cur=pos[pr].back(); pos[pr].pop_back();
            adj[i].push_back(cur);
            ind[cur]++;
        }
        pos[ord[a[i]]].push_back(i);
    }
    for(int i=0;i<m;i++) if(!ind[i]) make_dfs(i,-1,0);
    
    vector<pair<pii,int>> qa;
    for(int i=0;i<q;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        l--; r--;
        qa.push_back(make_pair(pii(l,r),i));
    }
    sort(qa.begin(),qa.end());
    
    set<pii> tr;
    for(int i=0;i<q;i++) ans[i]='0';
    for(int i=0,j=0;i<m;i++) {
        while(!tr.empty() && tr.begin()->fi < i) tr.erase(tr.begin());
        for(;j<q && qa[j].fi.fi<=i;j++) tr.insert(pii(qa[j].fi.se,qa[j].se));
        
        int r=get_ep(i,n-1);
        if(r==-1) continue;
        auto it = tr.lower_bound(pii(r,-1));
        while(it!=tr.end()) {
            ans[it->se]='1';
            it=tr.erase(it);
        }
    }
    printf("%s\n",ans);
        
    return 0;
}