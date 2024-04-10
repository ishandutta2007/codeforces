// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

const int N=200005;
const int mod=998244353;

inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return res;
}

vector<array<int,3>> adj[N];
vector<int> inz[N];
int inv[N],ans[N];
bool vis[N];

int now[N],least[N],n;
void dfs1(int u){
    vis[u]=1;
    for(auto [v,x,y]:adj[u]){
        if(vis[v])continue;
        for(auto it:inz[x])now[it]--;
        for(auto it:inz[y])now[it]++;
        for(auto it:inz[x])ckmin(least[it],now[it]);
        for(auto it:inz[y])ckmin(least[it],now[it]);
        dfs1(v);
        for(auto it:inz[x])now[it]++;
        for(auto it:inz[y])now[it]--;
    }
}
void dfs2(int u){
    vis[u]=1;
    for(auto [v,x,y]:adj[u]){
        if(vis[v])continue;
        ans[v]=ans[u];
        for(auto it:inz[x])ans[v]=1ll*ans[v]*inv[it]%mod;
        for(auto it:inz[y])ans[v]=1ll*ans[v]*it%mod;
        dfs2(v);
    }
}

void solve(){
    n=read();
    rep(i,1,n)adj[i].clear(),least[i]=0,vis[i]=0;
    rep(i,1,n-1){
        int u=read(),v=read(),x=read(),y=read();
        adj[u].pb({v,x,y});
        adj[v].pb({u,y,x});
    }
    dfs1(1);
    ans[1]=1;
    rep(i,1,n){
        if(least[i]<0){
            ans[1]=1ll*ans[1]*qpow(i,-least[i])%mod;
        }
    }
    rep(i,1,n)vis[i]=0;
    // fprintf(stderr,"ans[1]=%d\n",ans[1]);
    dfs2(1);
    int ANS=0;
    // rep(i,1,n)printf("ans[%d]=%d\n",i,ans[i]);
    rep(i,1,n)ANS=(ANS+ans[i])%mod;
    print(ANS,'\n');
}

int main(){
    for(int i=2;i<N;i++){
        if(!vis[i]){
            for(int j=i;j<N;j+=i){
                int tmp=j;
                while(tmp%i==0)tmp/=i,inz[j].pb(i);
            }
            for(int j=i+i;j<N;j+=i)
                vis[j]=1;
        }
    }
    inv[1]=1;
    rep(i,2,N-1)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    int T=read();
    while(T--)solve();
    return 0;
}