// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

struct DSU{
    vector<int> f,tag;
    void init(int n){f.resize(n+1),tag.resize(n+1),iota(f.begin()+1,f.begin()+n+1,1);}
    int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return;
        tag[y]|=tag[x];
        f[x]=y;
    }
    bool check(int x,int y){return find(x)==find(y);}
}dsu[30],ALL;

int n,m,q;

int main(){
    n=read(),m=read();
    rep(j,0,29)dsu[j].init(n);
    ALL.init(30*n);
    vector<pii> sav;
    rep(i,1,m){
        int u=read(),v=read(),w=read();
        rep(j,0,29)
            if(w>>j&1)
                dsu[j].merge(u,v);
        if(w%2==1){
            rep(j,1,29)
                if(w>>j&1)
                    ALL.merge(j*n+u,j*n+v);
        }else{
            sav.pb({u,v});
        }
    }
    for(auto [u,v]:sav){
        rep(j,1,29){
            ALL.tag[ALL.find(j*n+u)]=1;
            ALL.tag[ALL.find(j*n+v)]=1;
        }
    }
    q=read();
    while(q--){
        int u=read(),v=read();
        bool flag=0;
        rep(j,0,29)flag|=dsu[j].check(u,v);
        if(flag){puts("0");continue;}
        rep(j,1,29)flag|=ALL.tag[ALL.find(j*n+u)];
        // flag|=ALL.check(u,v);
        if(flag)puts("1");
        else puts("2");
    }
    return 0;
}