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

const int N=6005;

vector<int> adj[N];
int n;

bool vis[N];
int dep[N],dad[N];
int cir[N],len;
void dfs(int u,int fa){
    vis[u]=1,dad[u]=fa;
    // printf("dfs u=%d,fa=%d\n",u,fa);
    for(auto v:adj[u]){
        if(v==fa)continue;
        if(!vis[v]){
            dep[v]=dep[u]+1;
            dfs(v,u);
        }else if(dep[v]<dep[u]){
            len=0;
            for(int i=u;;i=dad[i]){
                cir[++len]=i;
                if(i==v)break;
            }
        }
    }
}

int main(){
    n=read();
    rep(i,1,2*n){
        int x=read(),y=read();
        adj[x].pb(y),adj[y].pb(x);
    }
    ll ans=0;
    rep(i,1,2*n)if(!vis[i]){
        dfs(i,0);
        // for(int j=1;j<=len;j++)printf("%d ",cir[j]);puts("");
        cir[0]=cir[len];
        for(int j=1;j<=len;j++)cir[j+len]=cir[j];
        for(int l=1;l<=len;l++){
            int min1=1e9,max1=-1e9;
            int min2=1e9,max2=-1e9;
            for(int r=l;r<l+len;r+=2){
                // printf("now deal [%d,%d]\n",cir[l],cir[r]);
                if(l==r){
                    if(cir[l]<=n)ckmin(min1,cir[l]),ckmax(max1,cir[l]);
                    else ckmin(min2,cir[l]-n),ckmax(max2,cir[l]-n);
                }else{
                    if(cir[r]<=n)ckmin(min1,cir[r]),ckmax(max1,cir[r]);
                    else ckmin(min2,cir[r]-n),ckmax(max2,cir[r]-n);
                    if(cir[r-1]<=n)ckmin(min1,cir[r-1]),ckmax(max1,cir[r-1]);
                    else ckmin(min2,cir[r-1]-n),ckmax(max2,cir[r-1]-n);
                }
                // printf("min1=%d,max1=%d,min2=%d,max2=%d\n",min1,max1,min2,max2);
                if(cir[l-1]<=n){
                    int x=cir[l-1],y=cir[r+1];
                    if(x>y)swap(x,y);
                    vector<pii> tmp;
                    tmp.pb({1,x-1}),tmp.pb({x+1,y-1}),tmp.pb({y+1,n});
                    for(auto [L,R]:tmp){
                        if(L>R)continue;
                        if(L>min1||R<max1)continue;
                        if(min1==1e9)ans-=1ll*(R-L+1)*(R-L+2)/2*min2*(n-max2+1);
                        else ans-=1ll*(min1-L+1)*(R-max1+1)*min2*(n-max2+1);
                    }
                }else{
                    int x=cir[l-1]-n,y=cir[r+1]-n;
                    if(x>y)swap(x,y);
                    vector<pii> tmp;
                    tmp.pb({1,x-1}),tmp.pb({x+1,y-1}),tmp.pb({y+1,n});
                    for(auto [L,R]:tmp){
                        if(L>R)continue;
                        if(L>min2||R<max2)continue;
                        if(min2==1e9)ans-=1ll*(R-L+1)*(R-L+2)/2*min1*(n-max1+1);
                        else ans-=1ll*(min2-L+1)*(R-max2+1)*min1*(n-max1+1);
                    }
                }
                // printf("ans=%lld\n",ans);
                // system("pause");
            }
        }
    }
    // printf("ans=%lld\n",ans);
    rep(i,1,n){
        ans+=1ll*i*(n-i+1)*n*(n+1);
    }
    print(ans/2,'\n');
    return 0;
}