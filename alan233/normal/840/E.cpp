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

const int N=50005;

vector<int>adj[N];
int n,q;
int a[N];

int stk[N],top;
int big[N][256],dep[N],anc[N],dad[N];

int ch[N][2],tot; 
int End[N];
void ins(int x,int dlt){
    int rt=0;
    per(i,7,0){
        int &t=ch[rt][x>>i&1];
        if(!t)t=++tot;
        rt=t;
    }
    End[rt]=dlt;
}
int qry(int x){
    int rt=0,ans=0;
    per(i,7,0){
        int type=x>>i&1;
        if(ch[rt][type^1]){
            ans^=1<<i+8;
            rt=ch[rt][type^1];
        }else{
            rt=ch[rt][type];
        }
    }    
    return ans^End[rt];
}

void dfs1(int u,int fa){
    stk[++top]=u,dep[u]=dep[fa]+1,dad[u]=fa;
    if(top>=256){
        static int val[256];
        while(tot){
            ch[tot][0]=ch[tot][1]=0;
            End[tot]=0;
            tot--;
        }
        ch[0][0]=ch[0][1]=0;
        rep(i,0,255)val[i]=-1;
        per(i,top,top-255){
            int t=(top-i)^a[stk[i]];
            ckmax(val[t/256],t&255);
        }
        rep(i,0,255){
            if(val[i]!=-1)ins(i,val[i]);
        }
        rep(i,0,255){
            big[u][i]=qry(i);
        }
        anc[u]=stk[top-256];
    }
    for(auto v:adj[u]){
        if(v==fa)continue;
        dfs1(v,u);
    }
    --top;
}

int main(){
    n=read(),q=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,n-1){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs1(1,0);
    while(q--){
        int u=read(),v=read(),tmpv=v,ans=0,now=0;
        while(dep[v]-dep[u]+1>=256){
            ckmax(ans,big[v][now]);
            v=anc[v],now++;
        }
        while(dep[v]>=dep[u]){
            ckmax(ans,(dep[tmpv]-dep[v])^a[v]);
            v=dad[v];
        }
        print(ans,'\n');
    }
    return 0;
}