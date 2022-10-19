#include <bits/stdc++.h>
#define maxn 150150
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define debug 
#define mk make_pair
#define pii pair<int,int>
#define mod 998244353 
using namespace std;

ll exp(ll a,ll b){
    if(b == 0)
        return 1;
    ll k = exp(a,b/2);
    k = (k*k) % mod;
    if(b&1)
        k = (k*a) % mod;
    return k;
}

#define div aaaaaaaaaaaaa
ll div(ll a,ll b){
    return (a * exp(b,mod-2)) % mod;
}

ll add = 0;

vector<int> L[maxn];

ll DS[maxn];
ll acc[maxn];
ll T[maxn];

void upd(int idx,ll val){
    idx++;
    while(idx < maxn){
        T[idx] = (T[idx]+val) % mod;
        idx += idx&-idx;
    }
}

ll qry(int idx){
    idx++;
    ll ret = 0;
    while(idx){
        ret = (ret + T[idx]) % mod;
        idx -= idx&-idx;
    }
    return ret;
}

void soma(int l,int r,ll val){
    upd(l,val);
    upd(r+1,mod-val);
}

int ini[maxn];
int fim[maxn];
int sub[maxn];
int heavy[maxn];
int pai[maxn];
int top[maxn];
int cur = 0;

void dfs(int vx,int p=-1){
    pai[vx] = p;
    ini[vx] = fim[vx] = cur++;
    sub[vx] = 1;
    heavy[vx] = -1;
    for(int i=0;i<L[vx].size();i++)
        if(L[vx][i] != p){
            int to = L[vx][i];
            dfs(to,vx);
            sub[vx] += sub[to];
            fim[vx] = fim[to];
            if(heavy[vx] == -1 || sub[to] > sub[heavy[vx]]){
                heavy[vx] = to;
                debug("%d -> %d\n",vx,to);
            }
        }
}

void dfs2(int vx,int p=-1){
    
    if(vx && heavy[p] == vx)
        top[vx] = top[p];
    else
        top[vx] = vx;
        
    debug("vx %d top %d heavy %d\n",vx,top[vx],heavy[vx]);
        
    for(int i=0;i<L[vx].size();i++)
        if(L[vx][i] != p)
            dfs2(L[vx][i],vx);
    
}

main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        L[a].pb(b);
        L[b].pb(a);
    }
    
    dfs(0);
    dfs2(0);
    
    for(int i=0;i<n;i++)
        DS[i] = div(sub[i],n);
    
    while(q--){
        int t,vx;
        scanf("%d%d",&t,&vx), vx--;
        if(t == 1){
            ll val;
            scanf("%lld",&val);
            add = (add+val) % mod;
            ll subUP = (div(n-sub[vx],n) * val) % mod;
            add = (add-subUP+mod) % mod;
            soma(ini[vx],fim[vx],subUP);
            acc[vx] = (acc[vx]+val) % mod;
            int kid = heavy[vx];
            if(kid == -1) continue;
            ll subt = (div(sub[kid],n) * val) % mod;
            soma(ini[kid],fim[kid],mod-subt);
        }
        else {
            ll ans = (add + qry(ini[vx])) % mod;
            while(1){
                vx = top[vx];
                int p = pai[vx];
                if(p == -1) break;
                debug("%d adds %lld\n",p,acc[p]);
                ll subt = (DS[vx] * acc[p]) % mod;
                ans = (ans-subt+mod) % mod;
                vx = p;
            }
            printf("%lld\n",ans);
        }
    }
}