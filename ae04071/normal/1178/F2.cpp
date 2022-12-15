#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lli = long long;
using pii = pair<int,int>;

const int MOD = 998244353;

int n,m,arr[1000000],li[501],ri[501],dp[1000][1000];
int lm[501],rm[501],lp[501],rp[501];
vector<pii> adj;

int DP(int l,int r) {
    if(l>=r) return 1;
    int &ret=dp[l][r];
    if(ret!=-1) return ret;

    int mx=n;
    for(int i=l;i<=r;i++) mx=min(mx,adj[i].first);

    int mv = DP(li[mx]+1,ri[mx]-1), lv=0, rv=0,cnt=0;
    cnt = 1;
    for(int j=li[mx];j>=l && lp[adj[j].fi]>lm[mx];j--) {
        cnt += adj[j].se;
        if(!cnt && adj[j].second==-1) lv = (lv + 1ll*DP(j,li[mx]-1)*DP(l,j-1)%MOD)%MOD;
    }
    cnt=-1;
    for(int j=ri[mx];j<=r && rp[adj[j].fi]<rm[mx];j++) {
        cnt+=adj[j].se;
        if(!cnt && adj[j].second==1) rv = (rv + 1ll*DP(ri[mx]+1,j)*DP(j+1,r)%MOD)%MOD;
    }
    //printf("%d %d : %d, %d %d, (%d %d %d)\n",l,r,mx,li[mx],ri[mx], lv,mv,rv);
    
    return ret = 1ll*lv*mv%MOD*rv%MOD;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d",arr+i);

    memset(li,-1,sizeof(li));
    memset(ri,-1,sizeof(ri));
    for(int i=0;i<m;i++) if(li[arr[i]]==-1) li[arr[i]]=i;
    for(int i=m-1;i>=0;i--) if(ri[arr[i]]==-1) ri[arr[i]]=i;
    for(int i=1;i<=n;i++) lm[i]=lp[i]=li[i],rm[i]=rp[i]=ri[i];
    
    vector<pii> tmp;
    for(int i=1;i<=n;i++) {
        tmp.push_back({li[i], i});
        tmp.push_back({ri[i]+1,-i});
    }
    sort(tmp.begin(),tmp.end());

    set<int> tr;
    for(int i=0,j=0;i<m;i++) {
        while(j<(int)tmp.size() && tmp[j].fi<=i) {
            if(tmp[j].se<0) tr.erase(-tmp[j].se);
            else tr.insert(tmp[j].se);
            j++;
        }
        if(tr.upper_bound(arr[i])!=tr.end()) {
            puts("0");
            return 0;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int &j=lm[i];j>=0 && arr[j]>=i;j--);
        for(int &j=rm[i];j<m && arr[j]>=i;j++);
    }

    for(int i=1;i<=n;i++) {
        adj.push_back({i,-1});
        adj.push_back({i,1});
    }
    sort(adj.begin(),adj.end(),[&](const pii &a, const pii &b) {
        int ai = a.se==-1 ? li[a.fi] : ri[a.fi];
        int bi = b.se==-1 ? li[b.fi] : ri[b.fi];
        return ai==bi ? a.se<b.se : ai<bi;
    });
    for(int i=0;i<n*2;i++) {
        if(adj[i].se==-1) li[adj[i].fi]=i;
        else ri[adj[i].fi]=i;
    }

    memset(dp,-1,sizeof(dp));
    printf("%d\n",DP(0,n*2-1));

    return 0;
}