#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int INF = 1e9;
struct seg_tr{
    const static int MAX = 1<<18;
    struct node{
        int a[9];
        node() {
            for(int i=0;i<9;i++) a[i] = 0;
        }
    }tr[MAX<<1];
    int tv[MAX<<1];

    int getAns(node &a, node &b) {
        int ans = -1;
        for(int i=0;i<9;i++) if(a.a[i] && b.a[i]) {
            if(ans==-1) ans = a.a[i] + b.a[i];
            else ans = min(ans, a.a[i] + b.a[i]);
        } return ans;
    }
    void merge(node &tar,node &a,node &b) {
        for(int i=0;i<9;i++) {
            if(!a.a[i]) tar.a[i] = b.a[i];
            else if(!b.a[i]) tar.a[i] = a.a[i];
            else tar.a[i] = min(a.a[i], b.a[i]);
        }
    }
    void upd(int cur,int s,int f,int idx,int val) {
        if(f<idx || s>idx) return;
        else if(s==f) {
            int v=val;
            for(int i=0;i<9;i++) {
                if(v%10) tr[cur].a[i] = val;
                else tr[cur].a[i] = 0;
                v/=10;
            }
            tv[cur] = -1;
        } else {
            int nx=cur<<1,md=(s+f)>>1;
            upd(nx,s,md,idx,val); upd(nx+1,md+1,f,idx,val);
            merge(tr[cur], tr[nx], tr[nx+1]);
            tv[cur] = getMax(getMax(tv[nx], tv[nx+1]), getAns(tr[nx],tr[nx+1]));
        }
    }
    int getMax(int a,int b) {
        if(a==-1) return b;
        else if(b==-1) return a;
        else return min(a,b);
    }
    void upd(int idx,int val) {
        upd(1,0,MAX-1,idx,val);
    }
    pair<node,int> get(int cur,int s,int f,int l,int r) {
        if(f<l || s>r) return {node(), -1};
        else if(l<=s && f<=r) return {tr[cur], tv[cur]};
        else {
            int nx=cur<<1,md=(s+f)>>1;
            pair<node,int> a = get(nx,s,md,l,r), b = get(nx+1,md+1,f,l,r);
            node ret; merge(ret, a.fi, b.fi);
            return {ret, getMax(getMax(a.se, b.se), getAns(a.fi,b.fi))};
        }
    }
    int get(int l,int r) {
        return get(1,0,MAX-1,l,r).se;
    }
}st;

int n,m;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        int v;
        scanf("%d",&v);
        st.upd(i,v);
    }
    while(m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1) st.upd(b,c);
        else printf("%d\n",st.get(b,c));
    }
    return 0;
}