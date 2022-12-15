#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pll = pair<lli,lli>;
using pli = pair<lli,int>;

struct seg_tr{
    const static int MAX = 1<<18;
    int tr[MAX<<1];

    void push(int cur) {
        int nx = cur<<1;
        tr[nx] = max(tr[nx], tr[cur]);
        tr[nx+1] = max(tr[nx+1],tr[cur]);
        tr[cur]=0;
    }
    void upd(int cur,int s,int f,int idx,int val) {
        if(s==f) tr[cur] = val;
        else {
            push(cur);
            int nx=cur<<1,md=(s+f)>>1;
            if(idx<=md) upd(nx,s,md,idx,val);
            else upd(nx+1,md+1,f,idx,val);
        }
    }
    void dis(int val) {
        tr[1] = max(tr[1], val);
    }
    void pushAll() {
        for(int i=0;i<MAX;i++) {
            push(i);
        }
    }
}st;
int n;

int main() {
    priority_queue<pii,vector<pii>,greater<pii>> que;
    scanf("%d",&n);
    for(int i=0,v;i<n;i++) {
        scanf("%d",&v);
        st.upd(1,0,st.MAX-1,i,v);
    }

    int q;
    scanf("%d",&q);
    while(q--) {
        int t,a,b;
        scanf("%d",&t);
        if(t==1) {
            scanf("%d%d",&a,&b);

            st.upd(1,0,st.MAX-1,--a,b);
        } else {
            scanf("%d",&b);
            st.dis(b);
        }
    }
    st.pushAll();
    for(int i=0;i<n;i++) printf("%d ",st.tr[i+st.MAX]);

    return 0;
}