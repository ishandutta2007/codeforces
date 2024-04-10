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

const int N=100005;

struct Edge{
    int to,nxt,id;
}edge[N<<1];
int head[N],etot;
void add(int u,int v,int id){
    edge[++etot]={v,head[u],id};
    head[u]=etot;
}

int n,m;

ll a[N],ans[N];
bool treeEdge[N],vis[N];
int dep[N],dad[N],dadE[N];
void dfs1(int u,int fa,int lst){
//    printf("dfs1 u=%d, fa=%d, lst=%d\n",u,fa,lst);
    vis[u]=1,dep[u]=dep[fa]+1;
    ans[lst]=a[u];
    dad[u]=fa,dadE[u]=lst;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(vis[v])continue;
        treeEdge[edge[i].id]=1;
        dfs1(v,u,edge[i].id);
        ans[lst]-=ans[edge[i].id];
    }
}

int main(){
    n=read(),m=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,m){
        int u=read(),v=read();
        add(u,v,i),add(v,u,i);
    }
    dfs1(1,0,0);
    if(!ans[0]){
        puts("YES");
        rep(i,1,m){
            printf("%lld\n",ans[i]);    
        }
        return 0;
    }
//    rep(i,0,m){
//        printf("ans[%d]=%lld\n",i,ans[i]);
//    }
    bool ok=0;
    rep(i,1,m){
        if(treeEdge[i])continue;
        int u=edge[2*i].to,v=edge[2*i-1].to;
        if((dep[u]-dep[v])&1)continue;
        if(ans[0]%2==0){
            ll K=ans[0]/2;
//            printf("K=%lld\n",K);
            ok=1;
            if(dep[u]<dep[v])swap(u,v);
            if(dep[u]%2==0)K*=-1;
            ans[i]=K;
            int opt=-1;
            while(u!=v){
                ans[dadE[u]]+=opt*K;
                opt*=-1;
                u=dad[u];
            }
            opt=-1;
            while(u){
                ans[dadE[u]]+=opt*2*K;
                u=dad[u];
                opt*=-1;
            }
            break;
        }
    }
//    assert(ans[0]==0);
    if(ok){
        puts("YES");
        rep(i,1,m){
            printf("%lld\n",ans[i]);
        }
    }else{
        puts("NO");
    }
    return 0;
}

/*
6 6
3 5 5 5 1 5
1 4
3 2
4 3
4 5
3 5
5 6
*/