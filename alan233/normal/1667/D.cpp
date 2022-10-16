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

vector<int> adj[N];
int deg[N],jb[N];
bool wa;
int n;

int dfs1(int u,int fa){
    int odd=deg[u]+1>>1,even=deg[u]>>1;
    for(auto v:adj[u]){
        if(v==fa)continue;
        int t=dfs1(v,u);
        // printf("here %d %d %d\n",u,v,t);
        if(t)odd--;else even--;
    }
    if(odd<0||even<0){
        wa=1;
        return 0;
    }
    else if(odd){
        jb[u]=1;return 1;
    }else{
        jb[u]=0;return 0;
    }
}
void dfs2(int u,int fa){
    vector<int> zz[2];
    if(u!=1)zz[jb[u]].pb(u);
    for(auto v:adj[u]){
        if(v==fa)continue;
        zz[jb[v]].pb(v);
    }
    int now=deg[u]&1;
    while(SZ(zz[now])){
        int ver=zz[now].back();zz[now].pop_back();
        if(ver==u)printf("%d %d\n",fa,u);
        else dfs2(ver,u);
        now^=1;
    }
}

int main(){
    int T=read();
    while(T--){
        n=read();
        rep(i,1,n)deg[i]=0,adj[i].clear();wa=0;
        rep(i,1,n-1){
            int u=read(),v=read();
            adj[u].pb(v),adj[v].pb(u);
            deg[u]++,deg[v]++;
        }
        dfs1(1,0);
        if(wa)puts("NO");
        else{
            // rep(i,1,n)printf("jb[%d]=%d\n",i,jb[i]);
            puts("YES");
            dfs2(1,0);
        }
    }
    return 0;
}