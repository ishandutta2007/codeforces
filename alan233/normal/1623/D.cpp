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

const int N=200005;
const int mod=1e9+7;

inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;b>>=1;
    }
    return res;
}

int n,m,rb,cb,rd,cd;
int p;

int type(int dirx,int diry){
    if(dirx==1){
        if(diry==1)return 0;
        else return 1;
    }else{
        if(diry==1)return 2;
        else return 3;
    }
}

void solve(){
    n=read(),m=read();
    vector<vector<vector<int>>>vis;
    vis.resize(n+1);
    rep(i,1,n){
        vis[i].resize(m+1);
        rep(j,1,m)vis[i][j].resize(4,-1);
    }
    rb=read(),cb=read(),rd=read(),cd=read(),p=1ll*read()*qpow(100)%mod;
    int dirx=1,diry=1;
    vis[rb][cb][type(dirx,diry)]=0;
    vector<int>step;
    if(rb==rd||cb==cd)step.pb(0);
    int times=0,beg=0;
    while(1){
        if(dirx==1&&rb==n)dirx=-1;
        if(dirx==-1&&rb==1)dirx=1;
        if(diry==1&&cb==m)diry=-1;
        if(diry==-1&&cb==1)diry=1;
        rb+=dirx,cb+=diry;
        times++;
        if(vis[rb][cb][type(dirx,diry)]!=-1){
            beg=vis[rb][cb][type(dirx,diry)];
            break;
        }else{
            vis[rb][cb][type(dirx,diry)]=times;
        }
        if(rb==rd||cb==cd)step.pb(times);
    }
    times--;
//    printf("times=%d\n",times);
//    printf("beg=%d\n",beg);
//    for(auto it:step)printf("%d ",it);puts("");
    
    int preP=1,ans=0;
    int period=times-beg+1;
    int jy=0;
    for(auto it:step)if(it>=beg)jy++;
    int fuck=qpow(mod+1-qpow(mod+1-p,jy));
    int q=qpow(mod+1-p,jy);
    int _=1ll*q*qpow(mod+1-q)%mod*qpow(mod+1-q)%mod;
    
    for(int i=0;i<SZ(step);i++){
        if(step[i]<beg){
            ans=(ans+1ll*preP*p%mod*step[i])%mod;
            preP=1ll*preP*(mod+1-p)%mod;
        }
        if(step[i]>=beg){
            ans=(ans+1ll*p*step[i]%mod*preP%mod*fuck)%mod;
            ans=(ans+1ll*preP*p%mod*period%mod*_)%mod;
            preP=1ll*preP*(mod+1-p)%mod;
        }
    }
    printf("%d\n",ans);    
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}