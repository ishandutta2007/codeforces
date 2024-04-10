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
const int inf=1e9;

int L[N],R[N],p[N];
int dp[N];

set<int> zz; // 
int n,A,B;

/*
#define ls (u<<1)
#define rs (u<<1|1)

vector<int> segs[N<<2],tmp;
void clr(int u,int l,int r){
    segs[u].clear(),segs[u].shrink_to_fit();
    if(l==r)return;
    int mid=l+r>>1;
    clr(ls,l,mid),clr(rs,mid+1,r);
}
void put(int u,int l,int r,int ql,int qr,int id){
    if(ql<=l&&r<=qr){
        segs[u].pb(id);
        return;
    }
    int mid=l+r>>1;
    if(ql<=mid)put(ls,l,mid,ql,qr,id);
    if(qr>mid)put(rs,mid+1,r,ql,qr,id);
}
void query(int u,int l,int r,int pos){
    for(auto it:segs[u]){
        if(!vis[it])tmp.pb(it);
    }
    segs[u].clear();
    if(l==r)return;
    int mid=l+r>>1;
    if(pos<=mid)query(ls,l,mid,pos);
    else query(rs,mid+1,r,pos);
}
*/

struct SMT{
    #define ls (u<<1)
    #define rs (u<<1|1)

    pii minn[N<<2];

    void update(int u,int l,int r,int pos,int dlt){
        if(l==r){
            minn[u]={dlt,l};
            return;
        }
        int mid=l+r>>1;
        if(pos<=mid)update(ls,l,mid,pos,dlt);
        else update(rs,mid+1,r,pos,dlt);
        minn[u]=min(minn[ls],minn[rs]);
    }  
    pii query(int u,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr)return minn[u];
        int mid=l+r>>1;
        if(qr<=mid)return query(ls,l,mid,ql,qr);
        if(ql>mid)return query(rs,mid+1,r,ql,qr);
        return min(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
    }
}smtL,smtR;

void solve(){
    n=read(),A=read(),B=read();
    rep(i,1,n)p[i]=read();
    rep(i,1,n){
        L[i]=max(1,i-p[i]),R[i]=min(n,i+p[i]);
        smtL.update(1,1,n,i,L[i]);
        smtR.update(1,1,n,i,-R[i]);
    }
    queue<int> q;
    dp[A]=0,q.push(A);
    smtL.update(1,1,n,A,inf);
    smtR.update(1,1,n,A,inf);
    while(!q.empty()){
        int u=q.front();q.pop();
        while(R[u]>u){
            pii k=smtL.query(1,1,n,u+1,R[u]);
            if(k.fir>u)break;
            int v=k.sec;
            smtL.update(1,1,n,v,inf);
            smtR.update(1,1,n,v,inf);
            dp[v]=dp[u]+1;
            q.push(v);
        }
        while(L[u]<u){
            pii k=smtR.query(1,1,n,L[u],u-1);
            if(-k.fir<u)break;
            int v=k.sec;
            smtL.update(1,1,n,v,inf);
            smtR.update(1,1,n,v,inf);
            dp[v]=dp[u]+1;
            q.push(v);
        }
    }
    print(dp[B],'\n');
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}