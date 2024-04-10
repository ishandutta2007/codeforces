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

const int N=2005;
const int mod=998244353;

char a[N][N],b[N][N];
int n,m;

vector<int> adj[N<<1];
int w[N<<1];
bool vis[N<<1];
int V,E,par;
void dfs(int u){
    // printf("dfs %d\n",u);
    vis[u]=1,V++,E+=SZ(adj[u]),par^=w[u];
    for(auto v:adj[u])if(!vis[v])dfs(v);
}

int spow(int x){ // slow pow
    int res=1;
    while(x--)res=2*res%mod;
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%s",a[i]+1);
    if(n%2>m%2){
        rep(i,1,n)
            rep(j,1,m)
                b[j][i]=a[i][j];
        memcpy(a,b,sizeof(b));
        swap(n,m);
    }
/*    
    printf("n=%d,m=%d\n",n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            putchar(a[i][j]);
        putchar('\n');
    }
*/
    if(n%2==0&&m%2==0){
        int _=0;
        rep(i,1,n)_+=count(a[i]+1,a[i]+m+1,'?');
        int res=1;
        while(_--)res=2*res%mod;
        printf("%d\n",res);
        return 0;
    }
    if(n%2==0){
        int _1=0,flag1=1,_2=0,flag2=1;
        for(int i=1;i<=n;i++){
            int s=0,_=0;
            for(int j=1;j<=m;j++){
                if(a[i][j]=='1')s^=1;
                if(a[i][j]=='?')_++;
            }
            if(!_&&s)flag1=0;
            if(!_&&!s)flag2=0;
            _1+=max(0,_-1);
            _2+=max(0,_-1);
        }
        int res1=1,res2=1;
        if(flag1){
            while(_1--)
                res1=2*res1%mod;
        }else{
            res1=0;
        }
        if(flag2){
            while(_2--)
                res2=2*res2%mod;
        }else{
            res2=0;
        }
        printf("%d\n",(res1+res2)%mod);
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='1')
                w[i]^=1,w[j+n]^=1;
            if(a[i][j]=='?')
                adj[i].pb(j+n),adj[j+n].pb(i);
        }
    }
    int res1=1,res2=1;
    for(int i=1;i<=n+m;i++){
        if(!vis[i]){
            V=0,E=0,par=0,dfs(i);
            // assert(V%2==0);
            E=E/2-(V-1);
            // printf("V=%d,E=%d,par=%d\n",V,E,par);
            if(V&1){
                if(par)res1=1ll*res1*spow(E)%mod,res2=0;
                else res2=1ll*res2*spow(E)%mod,res1=0;
            }else{
                if(par)res1=res2=0;
                else res1=1ll*res1*spow(E)%mod,res2=1ll*res2*spow(E)%mod;
            }
        }
    }
    printf("%d\n",(res1+res2)%mod);
    return 0;
}