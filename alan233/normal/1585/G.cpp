#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("avx","avx2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=500005;
const int inf=1e9;

vector<int>adj[N];

int fake_dp[5*N],*f[N],*g[N],*it;
int n;

int len[N],mlen[N],son[N];
void dfs1(int u){
    len[u]=son[u]=0;
    mlen[u]=inf;
    for(auto v:adj[u]){
        dfs1(v);
        if(len[v]+1>len[u])
            len[u]=len[v]+1,son[u]=v;
        mlen[u]=min(mlen[u],mlen[v]+1);
    }
    if(mlen[u]==inf)mlen[u]=0;
}
int SG[N];
int tmp[N<<2];
void dfs2(int u){
    if(!son[u]){
        SG[u]=1;
        f[u][0]=1,g[u][0]=1,g[u][1]=1;
        return;
    }
    f[son[u]]=f[u]+1,g[son[u]]=g[u],dfs2(son[u]);
    if(mlen[u]!=mlen[son[u]]+1){
        for(int i=mlen[u]+2;i<=mlen[son[u]]+2;i++){
            g[u][f[u][i]]--;
        } 
    } 
    bool have=0;
    for(auto v:adj[u]){
        if(v==son[u])continue;
//        qwq=min(qwq,mlen[v]);
        have=1;
        f[v]=it,it+=len[v]+2;
        g[v]=it,it+=2*len[v]+1;
        dfs2(v);
        for(int i=0;i<=mlen[u];i++){
            g[u][f[u][i+1]]--;
            f[u][i+1]^=f[v][i];
            g[u][f[u][i+1]]++;
        }
    }
//    printf("u=%d,len=%d,mlen=%d\n",u,len[u],mlen[u]);
//    for(int i=1;i<=mlen[u]+1;i++)printf("f[%d][%d]=%d\n",u,i,f[u][i]);
//    set<int>s1,s2;
//    
//    for(int i=0;i<=2*len[u];i++)if(g[u][i])s1.insert(i);
//    for(int i=1;i<=mlen[u]+1;i++)s2.insert(f[u][i]);
//    if(s1!=s2){
//        printf("fuck %d\n",u);
//        for(auto v:s1)printf("%d ",v);puts("");
//        for(auto v:s2)printf("%d ",v);puts("");
//        system("pause");
//    }
    
    if(!have){
        SG[u]=SG[son[u]];
        while(g[u][SG[u]])SG[u]++;
    }else{
        for(int i=1;i<=mlen[u]+1;i++)tmp[f[u][i]]=1;
        SG[u]=0;while(tmp[SG[u]])SG[u]++;
        for(int i=1;i<=mlen[u]+1;i++)tmp[f[u][i]]=0;
    }
    f[u][0]=SG[u],g[u][SG[u]]++;
}
void solve(){
    n=read();
    rep(i,1,n)adj[i].clear();
    vector<int>roots;
    rep(i,1,n){
        int fa=read();
        if(!fa)roots.pb(i);
        else adj[fa].pb(i);
    }
    rep(i,1,5*n)fake_dp[i]=0;
    it=fake_dp;
    int ans=0;
    for(auto rt:roots){
        dfs1(rt);
        f[rt]=it,it+=len[rt]+2;
        g[rt]=it,it+=2*len[rt]+1;
        dfs2(rt);
        ans^=SG[rt];
    }
//    rep(i,1,n)printf("SG[%d]=%d\n",i,SG[i]); 
    puts(ans?"YES":"NO");
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}

/*
15
1
0
2
2 0
6
0 0 2 0 4 5
5
0 0 2 0 4
4
0 0 0 3
5
0 0 0 0 0
4
0 0 0 0
7
0 1 1 1 3 4 5
7
0 1 1 1 1 5 6
7
0 1 1 1 1 5 5
11
0 1 1 1 2 2 3 3 4 4 7
5
2 3 4 5 0
28
0 0 2 0 4 5 0 7 8 9 0 11 12 13 14 0 16 17 18 19 20 0 22 23 24 25 26 27
2
0 0
8
0 0 0 0 4 0 6 7
*/