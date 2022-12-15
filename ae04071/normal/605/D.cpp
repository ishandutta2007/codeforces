#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;

int n,a[100001],b[100001],c[100001],d[100001];
int vis[100001],pa[100001];
vector<int> xp;
struct seg_tr{
    const static int MAX=1<<17;
    vector<pii> tr[MAX<<1];
    int ci[MAX<<1];
    void init() {
        for(int i=MAX;i<MAX+MAX;i++) sort(tr[i].begin(),tr[i].end());
        for(int i=MAX-1;i;i--) {
            int j=0,k=0;
            int n1=i<<1,n2=i<<1|1;
            tr[i].resize(sz(tr[n1]) + sz(tr[n2]));
            int idx=0;
            while(j<sz(tr[n1]) || k<sz(tr[n2])) {
                if(j<sz(tr[n1]) && (k==sz(tr[n2]) || tr[n1][j].first < tr[n2][k].fi)) {
                    tr[i][idx++]=tr[n1][j++];
                }else{
                    tr[i][idx++]=tr[n2][k++];
                }
            }
        }
    }
    void bfs(int cur,int h,int u,queue<int> &que) {
        int l=MAX;
        cur+=MAX;
        while(l<=cur) {
            while(ci[cur] < sz(tr[cur]) && tr[cur][ci[cur]].fi <= h) {
                int v=tr[cur][ci[cur]++].se;
                if(!vis[v]) {
                    vis[v] = vis[u]+1;
                    pa[v]=u;
                    que.push(v);
                }
            }
            if(!(cur&1)) cur--;
            cur>>=1;
            if(l&1)l++;
            l>>=1;
        }
    }
}st;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
        xp.push_back(a[i]);
    }
    sort(xp.begin(),xp.end());
    xp.erase(unique(xp.begin(),xp.end()),xp.end());
    for(int i=1;i<=n;i++) {
        int idx = lower_bound(xp.begin(),xp.end(),a[i])-xp.begin();
        st.tr[idx+seg_tr::MAX].push_back(pii(b[i],i));
    }

    st.init();

    queue<int> que;
    for(int i=1;i<=n;i++) if(a[i]==0 && b[i]==0) {
        que.push(i);
        vis[i]=1;
    }
    while(!que.empty()) {
        int u=que.front();que.pop();
        int idx = upper_bound(xp.begin(),xp.end(),c[u])-xp.begin();
        if(idx!=0) st.bfs(idx-1,d[u],u,que);
    }

    if(vis[n]) {
        printf("%d\n",vis[n]);
        vector<int> stk;
        int cur=n;
        while(cur) {
            stk.push_back(cur);
            cur = pa[cur];
        }
        reverse(stk.begin(),stk.end());
        for(auto &it:stk) printf("%d ",it);
    } else {
        puts("-1");
    }
    
    return 0;
}