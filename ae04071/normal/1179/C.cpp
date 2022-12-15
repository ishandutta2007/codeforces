#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m,q;
struct seg_tr{
    const static int MAX = 1<<20;
    int tr[MAX<<1],lz[MAX<<1];
    void push(int cur) {
        tr[cur] += lz[cur];
        if(cur < MAX) {
            lz[cur<<1] += lz[cur];
            lz[cur<<1|1] += lz[cur];
        }
        lz[cur]=0;
    }
    int upd(int cur,int s,int f,int l,int r,int v) {
        push(cur);
        if(f<l || s>r) return tr[cur];
        else if(l<=s && f<=r) {
            lz[cur]+=v;
            push(cur);
            return tr[cur];
        } else{
            int nx=cur<<1,md=(s+f)>>1;
            return tr[cur] = max(upd(nx,s,md,l,r,v), upd(nx+1,md+1,f,l,r,v));
        }
    }
    void upd(int l,int r,int v) {
        upd(1,0,MAX-1,l,r,v);
    }
    int get(int cur,int s,int f) {
        if(s==f) return s;

        int nx=cur<<1,md=(s+f)>>1;
        push(nx); push(nx+1);
        if(tr[nx+1] > 0) return get(nx+1,md+1,f);
        else return get(nx,s,md);
    }
    int get() {
        return get(1,0,MAX-1);
    }
}st;

int a[300001],b[300001];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i), st.upd(1,a[i],1);
    for(int i=1;i<=m;i++) scanf("%d",b+i), st.upd(1,b[i],-1);
    
    scanf("%d",&q);
    while(q--) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u==1) {
            st.upd(1,a[v],-1);
            a[v] = w;
            st.upd(1,a[v],1);
        } else {
            st.upd(1,b[v],1);
            b[v] = w;
            st.upd(1,b[v],-1);
        }
        v = st.get();
        if(v==0) puts("-1");
        else printf("%d\n",v);
    }
    return 0;
}