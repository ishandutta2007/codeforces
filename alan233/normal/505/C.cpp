// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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

template<class T1,class T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<class T1,class T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}

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

const int N=32005;

gp_hash_table<int,int>dp[N];
int val[N],n,D;

void upd(int x,int y,int z){
    if(x>30000)return;
    if(dp[x].find(y)==dp[x].end())dp[x][y]=z;
    else ckmax(dp[x][y],z);
}

int main(){
    n=read(),D=read();
    rep(i,1,n)val[read()]++;
    dp[D][D]=0;
    int ans=0;
    rep(i,D,30000){
        for(auto &it:dp[i]){
            it.sec+=val[i],ckmax(ans,it.sec);
            if(it.fir>1)upd(i+it.fir-1,it.fir-1,it.sec);
            upd(i+it.fir,it.fir,it.sec);
            upd(i+it.fir+1,it.fir+1,it.sec);
        }
    }
    print(ans,'\n');
    return 0;
}