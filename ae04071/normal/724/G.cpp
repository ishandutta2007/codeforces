#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

const int MOD = 1000000007;

struct dsu {
    int pa[100001];
    dsu() {for(int i=0;i<=100000;i++) pa[i] = i;}
    int find(int cur) {return cur==pa[cur]?cur:pa[cur]=find(pa[cur]);}
    bool merge(int u,int v) {
        u=find(u),v=find(v);
        if(u==v) return false;
        pa[v]=u; return true;
    }
}dsu;
struct gauss{
    vector<lli> arr;
    void add(lli v) {arr.push_back(v);}
    pair<int, vector<int>> get_gauss() {
        vector<int> ret(60,0);
        int cnt=0;
        for(int j=0;j<60;j++) {
            lli v=0;
            for(auto &it:arr) if(it>>j&1) { v=it; break; }
            if(!v) {continue;} 
            else {
                cnt++;
                for(int k=0;k<60;k++) ret[k] |= v>>k&1;
                for(auto &it:arr) if(it>>j&1) it^=v;
            }
        }
        return {cnt, ret};
    }
    void init() {arr.clear();}
}gauss;

int n,m;
vector<pli> adj[100001];
vector<pair<pii,lli>> ei[100001];
int de[100001],ea[18][100001];
lli xl[100001];

vector<int> bv;
int bi,rnk;

void make_dfs(int cur,int p,int d,lli v){
    int a=1,pp=p;
    xl[cur]=v;
    for(auto &it:adj[cur]) if(it.se!=p) make_dfs(it.se,cur,d+1,v^it.fi);
}

lli ans=0;
pll DP(int cur,int p) {
    pll ret(1,0);
    for(auto &it:adj[cur]) if(it.se!=p) {
        pll t=DP(it.se,cur);
        if(it.fi>>bi&1) swap(t.fi,t.se);

        if(bv[bi]) ans = (ans + (1ll<<bi)%MOD * ((1ll<<(rnk-1))%MOD)%MOD * 
                ((ret.fi*t.se%MOD + ret.se*t.fi%MOD + 
                  ret.fi*t.fi%MOD + ret.se*t.se%MOD)%MOD)%MOD)%MOD;
        else ans = (ans + (1ll<<bi)%MOD * ((1ll<<rnk)%MOD)%MOD *
                (ret.fi*t.se%MOD + ret.se*t.fi)%MOD)%MOD;
        ret.fi+=t.fi; ret.se+=t.se;
    }
    
    return ret;
}

int main() {
    scanf("%d%d",&n,&m);
    
    vector<pair<pii,lli>> et;
    for(int i=0;i<m;i++) {
        int u,v;
        lli w;
        scanf("%d%d%lld",&u,&v,&w);
        if(!dsu.merge(u,v)) et.push_back({pii(u,v),w});
        else {
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }
    }
    for(auto &it:et) ei[dsu.find(it.fi.fi)].push_back(it);

    for(int i=1;i<=n;i++) if(dsu.find(i)==i) {
        gauss.init();
        make_dfs(i,0,0,0);
        for(auto &it:ei[i]) {
            gauss.add(it.se ^ xl[it.fi.fi] ^ xl[it.fi.se]);
        }
        
        tie(rnk, bv) = gauss.get_gauss();
        for(bi=0;bi<60;bi++) DP(i,0);
    }
    printf("%lld\n",ans);
    
    return 0;
}