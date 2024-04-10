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

vector<int>adj[N];
int n,m;

vector<int>side[2];
int type[N];
bool vis[N];
int ans[N];

void dfs1(int u){
    side[type[u]].pb(u);
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v])continue;
        type[v]=type[u]^1;
        dfs1(v);
    }    
}

int main(){
    n=read(),m=read();
    rep(i,1,m){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    rep(i,1,n){
        if(!vis[i]){
            dfs1(i);
        }
    }
    bool flag=n==105&&m==2380;
//    rep(i,0,1){
//        printf("side[%d]=",i);
//        for(auto it:side[i])printf("%d ",it);puts("");
//    }
    if(SZ(side[0])%3==0){
        int col=0;
        for(int i=0;i<SZ(side[0]);i+=3){
            ++col;
            ans[side[0][i]]=ans[side[0][i+1]]=ans[side[0][i+2]]=col;
        }
        for(int i=0;i<SZ(side[1]);i+=3){
            ++col;
            ans[side[1][i]]=ans[side[1][i+1]]=ans[side[1][i+2]]=col;
        } 
    }else{
        if(SZ(side[1])%3==1)swap(side[0],side[1]);
        int gg=-1,col=0;
        for(int i=0;i<SZ(side[0]);i++){
            int u=side[0][i];
            if(SZ(side[1])-SZ(adj[u])>=2){
                gg=i;
                break;
            }
        }
        if(gg==-1){
            static int qaq[N];
            static vector<int>who[N];
            int p=-1,q=-1;
            // n<=sqrt
            for(int i=0;i<SZ(side[0]);i++){
                int u=side[0][i];
                static bool vis[N]; 
                for(auto v:adj[u])vis[v]=1;
                for(int j=0;j<SZ(side[1]);j++){
                    int v=side[1][j];
                    if(!vis[v]){
                        qaq[v]++,who[j].pb(i);
                        if(qaq[v]==2){
                            if(p==-1)p=j;
                            else if(q==-1)q=j;
                        }
                    }
                }
                for(auto v:adj[u])vis[v]=0;
            }
            if(p==-1||q==-1){
                puts("NO");
                return 0;
            }
//            if(flag)assert(0);
            
//            printf("p=%d,q=%d\n",p,q);
            
            int col=0;
            for(int i=0,j=4;j<SZ(side[0]);i++,j+=3){
                ++col;
                while(i==who[p][0]||i==who[p][1]||i==who[q][0]||i==who[q][1])i++;
                ans[side[0][i]]=col;
                i++;while(i==who[p][0]||i==who[p][1]||i==who[q][0]||i==who[q][1])i++;
                ans[side[0][i]]=col;
                i++;while(i==who[p][0]||i==who[p][1]||i==who[q][0]||i==who[q][1])i++;
                ans[side[0][i]]=col;
            }
            for(int i=0,j=2;j<SZ(side[1]);i++,j+=3){
                ++col;
                while(i==p||i==q)i++;
                ans[side[1][i]]=col;
                i++;while(i==p||i==q)i++;
                ans[side[1][i]]=col;
                i++;while(i==p||i==q)i++;
                ans[side[1][i]]=col;
            }
            ++col,ans[side[1][p]]=ans[side[0][who[p][0]]]=ans[side[0][who[p][1]]]=col;
            ++col,ans[side[1][q]]=ans[side[0][who[q][0]]]=ans[side[0][who[q][1]]]=col;
        }else{
            static bool zz[N];
            for(auto v:adj[side[0][gg]])zz[v]=1;
            int p=-1,q=-1;
            for(int i=0;i<SZ(side[1]);i++){
                if(!zz[side[1][i]]){
                    if(p==-1)p=i;
                    else if(q==-1)q=i;
                }
            }
            for(int i=0,j=1;j<SZ(side[0]);i++,j+=3){
                ++col;
                while(i==gg)i++;
                ans[side[0][i]]=col;
                i++;while(i==gg)i++;
                ans[side[0][i]]=col;
                i++;while(i==gg)i++;
                ans[side[0][i]]=col;
            }
            for(int i=0,j=2;j<SZ(side[1]);i++,j+=3){
                ++col;
                while(i==p||i==q)i++;
                ans[side[1][i]]=col;
                i++;while(i==p||i==q)i++;
                ans[side[1][i]]=col;
                i++;while(i==p||i==q)i++;
                ans[side[1][i]]=col;
            }
            ++col,ans[side[0][gg]]=ans[side[1][p]]=ans[side[1][q]]=col;
        }
    }
    puts("YES");
    rep(i,1,n)printf("%d ",ans[i]);
    puts("");
    return 0;
}