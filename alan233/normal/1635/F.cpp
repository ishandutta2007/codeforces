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

const int N=300005;

ll ans[N];
ll a[N],w[N];
vector<pii> ask[N];
int n,q,stk[N],top;

struct Fen{
    ll c[N];
    void init(){
        memset(c,0x3f,sizeof(c));
    }
    void add(int x,ll dlt){
        while(x>0)ckmin(c[x],dlt),x-=x&-x;
    }
    ll qry(int x){
        ll ret=6e18;
        while(x<=n)ckmin(ret,c[x]),x+=x&-x;
        return ret;
    }
}tr;

int main(){
    n=read(),q=read();
    rep(i,1,n)a[i]=read(),w[i]=read();
    rep(i,1,q){
        int l=read(),r=read();
        ask[r].pb({l,i});
    }
    tr.init();
    rep(r,1,n){
        // printf("When r=%d\n",r);
        while(top){
            int l=stk[top];
            // printf("%d\n",l);
            tr.add(l,1ll*(a[r]-a[l])*(w[l]+w[r]));
            if(w[l]<w[r])break;
            else top--;
        }
        stk[++top]=r;
        for(auto [l,id]:ask[r])
            ans[id]=tr.qry(l);
    }
    rep(i,1,q)print(ans[i],'\n');
    return 0;
}