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

const int N = 200005;
const int M = 200005;
const int K = 11;

struct EdgeExist {
  int b1[N][N / (1 << K) + 3], bid;
  ull b2[M][1 << (K - 6)];
  void ins(int u, int v) {
    int id = v / (1 << K), v2 = v & ((1 << K) - 1);
    if (!b1[u][id]) b1[u][id] = ++bid;
    b2[b1[u][id]][v2 >> 6] |= 1ull << (v2 & 63);
  }
  void del(int u, int v) {
    int id = v / (1 << K), v2 = v & ((1 << K) - 1);
    b2[b1[u][id]][v2 >> 6] ^= 1ull << (v2 & 63);
  }
  void delb(int u, int v) {
    bid = 0;
    int id = v / (1 << K), v2 = v & ((1 << K) - 1);
    b1[u][id] = 0;
  }
  bool qry(int u, int v) {
    if (u < 1 || u >= N || v < 1 || v >= N) return 0;
    int id = v / (1 << K), v2 = v & ((1 << K) - 1);
    if (!b1[u][id]) return 0;
    return b2[b1[u][id]][v2 >> 6] >> (v2 & 63) & 1;
  }
} o;

map<pii,int> mp;
int x[N],y[N];
ll ans[N];pii ansc[N];
int n,id[N];

int main(){
    n=read();
    rep(i,1,n){
        x[i]=read(),y[i]=read();
        o.ins(x[i],y[i]);
        mp[{x[i],y[i]}]=i;
        id[i]=i;
    }
    sort(id+1,id+n+1,[&](int i,int j){
        return x[i]!=x[j]?x[i]<x[j]:y[i]<y[j];
    });
    rep(_,1,n){
        int i=id[_];
        int ansx,ansy,d=1;
        if(mp.count({x[i],y[i]-1}))ckmax(d,ans[mp[{x[i],y[i]-1}]]-1);
        if(mp.count({x[i],y[i]+1}))ckmax(d,ans[mp[{x[i],y[i]+1}]]-1);
        if(mp.count({x[i]-1,y[i]}))ckmax(d,ans[mp[{x[i]-1,y[i]}]]-1);
        if(mp.count({x[i]+1,y[i]}))ckmax(d,ans[mp[{x[i]+1,y[i]}]]-1);
        for(;;d++){
            int x=::x[i]-d,y=::y[i];
            for(int __=1;__<=d;__++){
                if(!o.qry(x,y)){
                    ansx=x,ansy=y;
                    goto end;
                }
                x++,y++;
            }
            for(int __=1;__<=d;__++){
                if(!o.qry(x,y)){
                    ansx=x,ansy=y;
                    goto end;
                }
                x++,y--;
            }
            for(int __=1;__<=d;__++){
                if(!o.qry(x,y)){
                    ansx=x,ansy=y;
                    goto end;
                }
                x--,y--;
            }
            for(int __=1;__<=d;__++){
                if(!o.qry(x,y)){
                    ansx=x,ansy=y;
                    goto end;
                }
                x--,y++;
            }
        }
        end: ;
        ans[i]=d,ansc[i]={ansx,ansy};
    }
    rep(i,1,n)
        printf("%d %d\n",ansc[i].fir,ansc[i].sec);
    return 0;
}