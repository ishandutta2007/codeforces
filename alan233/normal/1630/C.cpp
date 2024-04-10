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

const int N=1000005;

pii a[N];
int n,ans;

int main(){
    n=read();
    rep(i,1,n){
        int x=read();
        if(!a[x].fir)a[x].fir=a[x].sec=i;
        else a[x].sec=i;
    }
    sort(a+1,a+n+1);
    int las=0;
    rep(i,1,n){
        if(a[i].fir>=a[i].sec)continue;
        if(a[i].fir<las){
            int r=a[i].sec;
            while(i<n&&a[i+1].fir<las)ckmax(r,a[++i].sec);
            ans+=max(0,r-las-1);
            ckmax(las,r);
        }else{
            if(a[i].fir<a[i].sec){
                ans+=a[i].sec-a[i].fir-1,las=a[i].sec;
            }
        }
    }
    print(ans,'\n');
    return 0;
}