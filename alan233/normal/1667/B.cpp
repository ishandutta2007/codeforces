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

const int N=500005;
const int inf=1e9;

ll p[N],q[N];
int n,len;

struct Fen{
    int c[N];
    void init(int n,int vals=0){
        fill(c+1,c+n+1,vals);
    }
    void ins(int x,int delta){
        while(x<=len)ckmax(c[x],delta),x+=x&-x;
    }
    int qry(int x){
        int ret=-inf;
        while(x)ckmax(ret,c[x]),x^=x&-x;
        return ret;
    }
}tr1,tr2;
int las[N],dp[N];

void solve(){
    n=read();
    p[0]=0;
    rep(i,1,n)p[i]=p[i-1]+read(),q[i+1]=p[i];
    q[1]=0,sort(q+1,q+n+2),len=unique(q+1,q+n+2)-q-1;
    rep(i,0,n)p[i]=lower_bound(q+1,q+len+1,p[i])-q;

    tr1.init(len,-inf),tr2.init(len,-inf);
    rep(i,0,len)las[i]=-inf;

    // printf("len=%d\n",len);

    dp[0]=0;
    rep(i,0,n){
        // printf("p[%d]=%d\n",i,p[i]);
        if(i){
            int k1=tr1.qry(p[i]-1)+i;
            int k2=las[p[i]];
            int k3=tr2.qry(len-p[i])-i;
            dp[i]=max({k1,k2,k3});
        }
        tr1.ins(p[i],dp[i]-i);
        ckmax(las[p[i]],dp[i]);
        tr2.ins(len+1-p[i],dp[i]+i);
    }
    print(dp[n],'\n');
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}