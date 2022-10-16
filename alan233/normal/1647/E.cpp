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

int used[N],jp[30][N];
bool have[N],vis[N];ll con;
int n,p[N],a[N],mx,ans[N],least[N];

int fuck[N];
#define ls (u<<1)
#define rs (u<<1|1)
int maxx[N<<2],lazy[N<<2];
void pushup(int u){
    maxx[u]=max(maxx[ls],maxx[rs]);
}
void pushtag(int u,int dlt){maxx[u]+=dlt,lazy[u]+=dlt;}
void pushdown(int u){
    if(lazy[u])pushtag(ls,lazy[u]),pushtag(rs,lazy[u]),lazy[u]=0;
}
void build(int u,int l,int r){
    if(l==r){maxx[u]=fuck[l];return;}
    int mid=l+r>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    pushup(u);
}
void update(int u,int l,int r,int ql,int qr,int dlt){
    if(ql<=l&&r<=qr){pushtag(u,dlt);return;}
    pushdown(u);
    int mid=l+r>>1;
    if(ql<=mid)update(ls,l,mid,ql,qr,dlt);
    if(qr>mid)update(rs,mid+1,r,ql,qr,dlt);
    pushup(u);
}
int aim;
void query(int u,int l,int r,int ql,int qr){
    if(aim||maxx[u]<=0)return;
    if(l==r){aim=l;return;}
    pushdown(u);
    int mid=l+r>>1;
    if(ql<=l&&r<=qr){
        query(ls,l,mid,ql,qr);
        query(rs,mid+1,r,ql,qr);
        return;
    }
    if(ql<=mid)query(ls,l,mid,ql,qr);
    if(qr>mid)query(rs,mid+1,r,ql,qr);
}

int main(){
    n=read();
    rep(i,1,n){
        jp[0][i]=read();
        used[jp[0][i]]++;
    }
    rep(i,1,n)con+=max(0,used[i]-1);
    rep(i,1,n)a[i]=read(),ckmax(mx,a[i]);
    rep(j,1,29)
        rep(i,1,n)
            jp[j][i]=jp[j-1][jp[j-1][i]];
    // if((mx-n)%con)printf("mx=%d,n=%d,con=%lld\n",mx,n,con);
    // assert((mx-n)%con==0);
    ll turns=(mx-n)/con;
    rep(i,1,n){
        int ii=i;
        per(j,29,0)
            if(turns>>j&1)
                ii=jp[j][ii];
        if(!vis[ii])vis[ii]=1,ans[i]=a[ii],have[a[ii]]=1;
        least[i]=a[ii];
    }
    per(i,n,1)fuck[i]=fuck[i+1]+(!have[i]);
    build(1,1,n);
    rep(i,1,n)if(have[i])update(1,1,n,i,i,-1e9);
    rep(i,1,n)if(!ans[i])update(1,1,n,1,least[i],-1);
    rep(i,1,n){
        if(!ans[i]){
            int L=least[i];
            aim=0,query(1,1,n,L,n);
            assert(aim);
            update(1,1,n,L+1,aim,-1);
            update(1,1,n,aim,aim,-1e9);
            ans[i]=aim;
        }
        printf("%d ",ans[i]);
    }
    return 0;
}