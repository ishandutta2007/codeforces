#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;

const int MOD=1000000007;

int n,va[1000001],a[200001];
inline int power(int a,int p) {
    int res=1;
    while(p){
        if(p&1)res=1ll*res*a%MOD;
        a=1ll*a*a%MOD;
        p>>=1;
    }
    return res;
}
inline int inv(int a) {return power(a,MOD-2);}
struct seg_tr{
    int tr[200001];
    void init() {for(int i=1;i<=n;i++) tr[i]=1;}
    void upd(int cur,int val) {
        while(cur<=n) tr[cur]=1ll*tr[cur]*val%MOD,cur+=cur&-cur;
    }
    int sum(int cur) {
        int res=1;
        while(cur) res=1ll*res*tr[cur]%MOD,cur-=cur&-cur;
        return res;
    }
}seg_tr;

int m,ans[200001],iv[1000001];
vector<pair<int,int>> qa[200001];
vector<int> nxt[1000001];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);

    for(int i=2;i<=1000000;i++) if(!va[i]) {
        va[i]=i;
        if(i<=1000)for(int j=i*i;j<=1000000;j+=i) va[j]=i;
    }
    for(int i=1;i<=1000000;i++) iv[i] = inv(i);
    seg_tr.init();
    for(int i=1;i<=n;i++) {
        int v=a[i],p,res=a[i];
        while(v>1) {
            p=va[v];
            while(v%p==0) v/=p;
            nxt[p].push_back(i);
            if(sz(nxt[p])==1) res=1ll*res*(p-1)%MOD*iv[p]%MOD;
        }
        seg_tr.upd(i,res);
    }
    for(int i=1;i<=1000000;i++) reverse(nxt[i].begin(),nxt[i].end());

    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        qa[l].push_back({r,i});
    }
    for(int i=1;i<=n;i++) {
        for(auto &v:qa[i]) ans[v.se] = seg_tr.sum(v.fi);
        
        int res=iv[a[i]];
        int v=a[i],p;
        while(v>1) {
            p=va[v];
            while(v%p==0) v/=p;
            res=1ll*res*(p)%MOD*iv[p-1]%MOD;
            nxt[p].pop_back();
            if(!nxt[p].empty()) {
                seg_tr.upd(nxt[p].back(),1ll*(p-1)*iv[p]%MOD);
            }
        }
        seg_tr.upd(i,res);
    }
    for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    
    return 0;
}