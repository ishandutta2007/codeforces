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
#define poly vector<int>
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

const int N=200005;

vector<int>adj[N];
int n,m;

ll ans=1e18;

int dep[N],mdep[N],son[N],dad[N];
vector<int>a;
void dfs(int u,int fa){
    dep[u]=dep[fa]+1,mdep[u]=0,son[u]=0;
    dad[u]=fa;
    for(auto v:adj[u]){
        if(v==fa)continue;
        dfs(v,u);
        if(mdep[v]+1>mdep[u])mdep[u]=mdep[v]+1,son[u]=v;
    }
    for(auto v:adj[u]){
        if(v==fa)continue;
        if(v==son[u])continue;
        a.pb(mdep[v]);
    }
}
int main(){
    n=read(),m=read();
    rep(i,1,n-1){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs(1,0),a.pb(mdep[1]);
    sort(a.begin(),a.end());
    
//    for(auto v:a)printf("%d ",v);
//    puts("");
    
    if(m>=SZ(a)){
        int t=max(SZ(a),min(n/2,m));
        ans=1ll*t*(n-t);
    }else{
        ll sum=0;
        per(i,SZ(a)-1,SZ(a)-m)sum+=a[i];
        ll res=n-sum-m;
        rep(i,0,res)ckmin(ans,1ll*(sum+res-i)*(m-i));
    }
    printf("%lld\n",ans);
    return 0;
}