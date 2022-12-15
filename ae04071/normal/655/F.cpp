#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

const int MOD=1e9+7;

int n,m,k;
int vis[1000001],cnt[1000001],ret;
int cof[1000001],fact[1000001],ifact[1000001],ov;
vector<pii> arr;

int power(int a,int p) {
    int ret=1;
    while(p){
        if(p&1) ret = 1ll*ret*a%MOD;
        a=1ll*a*a%MOD;
        p>>=1;
    }
    return ret;
}
int inv(int a) { return power(a,MOD-2); }
int comb(int n,int k) {
    if(k<0 || k>n) return 0;
    else return 1ll*fact[n]*ifact[k]%MOD*ifact[n-k]%MOD;
}

void dfs(int idx,int v,int t) {
    if(idx==(int)arr.size()) {
        if(!t) {
            if(v!=ov) cof[ov] -= cof[v];
        } else {
            ret = ((ret - 1ll*cof[v]*comb(cnt[v],k)%MOD + MOD)%MOD);
            cnt[v]++;
            ret = (ret + 1ll*cof[v]*comb(cnt[v],k)%MOD)%MOD;
        }
        return;
    }
    for(int i=0;i<=arr[idx].se;i++) {
        dfs(idx+1,v,t);
        v*=arr[idx].fi;
    }
}
void proc(int val,int t)  {
    if(!t) cof[val] = ov = val;
    arr.clear();
    while(val>1) {
        int d=vis[val],c=0;
        while(val%d==0) val/=d,c++;
        arr.push_back({d,c});
    }
    dfs(0,1,t);
}

int main(){
    scanf("%d%d%d",&n,&k,&m);
    fact[0]=1;
    for(int i=1;i<=1000000;i++) fact[i]=1ll*fact[i-1]*i%MOD;
    for(int i=0;i<=1000000;i++) ifact[i] = inv(fact[i]);
    for(int i=2;i<=1000000;i++) if(!vis[i]) {
        vis[i]=i;
        if(i<=1000) for(int j=i*i;j<=1000000;j+=i) if(!vis[j])vis[j]=i;
    }
    for(int i=1;i<=1000000;i++) {
        proc(i,0);
    }

    int v;
    for(int i=0;i<n;i++) {
        scanf("%d",&v);
        proc(v,1);
    }
    for(int i=0;i<m;i++) {
        scanf("%d",&v);
        proc(v,1);
        printf("%d\n",ret);
    }
    
    return 0;
}