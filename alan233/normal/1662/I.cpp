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

struct node{
    int pos,delta;
    friend bool operator < (const node&x,const node&y){
        return x.pos!=y.pos?x.pos<y.pos:x.delta<y.delta;
    }
};
vector<node> qwq;

set<int> S;
int p[N],pos[N],n,m;

int main(){
    n=read(),m=read();
    rep(i,1,n){
        p[i]=read();
        pos[i]=100*(i-1);
    }
    rep(i,1,m){
        int x=read();
        S.insert(x);
    }
    rep(i,1,n){
        auto it=S.lower_bound(pos[i]);
        int dis=1e9;
        if(it!=S.end())ckmin(dis,*it-pos[i]);
        if(it!=S.begin())ckmin(dis,pos[i]-*prev(it));
        int L=2*(pos[i]-dis)+1,R=2*(pos[i]+dis)-1;
        // printf("When i=%d,L=%d,R=%d,p=%d\n",i,L,R,p[i]);
        if(L<=R)qwq.pb({L,p[i]}),qwq.pb({R+1,-p[i]});
    }
    sort(qwq.begin(),qwq.end());
    ll ans=0,now=0;
    for(auto [k1,k2]:qwq){
        now+=k2;
        ckmax(ans,now);
    }
    print(ans,'\n');
    return 0;
}