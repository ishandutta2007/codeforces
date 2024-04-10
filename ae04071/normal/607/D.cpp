#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MOD=1e9+7;

inline int power(int a,int p) {
    int ret=1;
    while(p) {
        if(p&1) ret = 1ll*ret*a%MOD;
        a=1ll*a*a%MOD;
        p>>=1;
    }
    return ret;
}
inline int inv(int a) {
    return power(a,MOD-2);
}
struct seg_tr{
    const static int MAX=1<<18;
    int tr[MAX<<1],lz[MAX<<1],lv[MAX<<1];
    seg_tr() {
        for(int i=0;i<MAX+MAX;i++) {
            tr[i]=0;
            lz[i]=1;
            lv[i]=1;
        }
    }
    void push(int cur) {
        if(lz[cur]!=1) {
            tr[cur] = 1ll*tr[cur]*lz[cur]%MOD;
            if(cur < MAX) {
                lz[cur<<1] = 1ll*lz[cur<<1]*lz[cur]%MOD;
                lz[cur<<1|1] = 1ll*lz[cur<<1|1]*lz[cur]%MOD;
                lz[cur]=1;
            } else {
                lv[cur] = 1ll*lv[cur]*lz[cur]%MOD;
                lz[cur] = 1;
            }
        }
    }
    int add(int cur,int s,int f,int idx,int val) {
        push(cur);
        if(f<idx || s>idx) return tr[cur];
        else if(s==f) return tr[cur]=val;
        else {
            int nx=cur<<1,md=(s+f)>>1;
            return tr[cur] = (add(nx,s,md,idx,val) + add(nx+1,md+1,f,idx,val))%MOD;
        }
    }
    void add(int idx,int val) {
        add(1,0,MAX-1,idx,val);
    }
    int upd(int cur,int s,int f,int l,int r,int m) {
        push(cur);
        if(f<l || s>r) return tr[cur];
        else if(l<=s && f<=r) {
            lz[cur] = 1ll*lz[cur]*m%MOD;
            push(cur);
            return tr[cur];
        } else {
            int nx=cur<<1,md=(s+f)>>1;
            return tr[cur] = (upd(nx,s,md,l,r,m) + upd(nx+1,md+1,f,l,r,m))%MOD;
        }
    }
    void upd(int l,int r,int m) {
        upd(1,0,MAX-1,l,r,m);
    }
    int get(int cur,int s,int f,int l,int r) {
        push(cur);
        if(f<l || s>r)return 0;
        else if(l<=s && f<=r) return tr[cur];
        else {
            int nx=cur<<1,md=(s+f)>>1;
            return (get(nx,s,md,l,r) + get(nx+1,md+1,f,l,r))%MOD;
        }
    }
    int get(int l,int r) {
        return get(1,0,MAX-1,l,r);
    }
    int getm(int cur,int s,int f,int idx) {
        push(cur);
        if(s==f) return lv[cur];
        else {
            int nx=cur<<1,md=(s+f)>>1;
            if(idx <= md) return getm(nx,s,md,idx);
            else return getm(nx+1,md+1,f,idx);
        }
    }
    int getm(int idx) {
        return getm(1,0,MAX-1,idx);
    }
}st;

int n,m,v[200001],d[200001],c[200001],dl[200001],dr[200001],df;
int pa[200001];
vector<int> adj[200001];

struct query{
    int t,p,v,ver;
}qa[200001];

void dfs(int cur,int p) {
    pa[cur] =p;
    dl[cur] = df++;
    for(auto &it:adj[cur]) dfs(it,cur);
    dr[cur] = df-1;
}
int main() {
    n=1;
    scanf("%d%d",v+1,&m);
    for(int i=0;i<m;i++) {
        scanf("%d",&qa[i].t);
        if(qa[i].t==1) {
            scanf("%d%d",&qa[i].p,&qa[i].v);
            adj[qa[i].p].push_back(++n);
            qa[i].ver = n;
        } else {
            scanf("%d",&qa[i].v);
        }
    }
    for(int i=1;i<=n;i++) d[i]=1;
    
    dfs(1,0);
    st.add(dl[1],v[1]);
    
    for(int i=0;i<m;i++) {
        if(qa[i].t==1) {
            int p=qa[i].p,u=qa[i].ver;
            if(d[p]!=0) st.upd(dl[p],dr[p],1ll*(d[p]+1)*inv(d[p])%MOD);
            d[p]++;
            
            int mm=st.getm(dl[p]);
            st.add(dl[u],1ll*qa[i].v*mm%MOD);
        } else {
            int v=st.get(dl[qa[i].v],dr[qa[i].v]);
            if(qa[i].v!=1) {
                int p=pa[qa[i].v];
                v = 1ll*v*inv(st.getm(dl[p]))%MOD;
            }
            printf("%d\n",v);
        }
    }
    
    return 0;
}