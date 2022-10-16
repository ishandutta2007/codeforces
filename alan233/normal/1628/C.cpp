// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
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

int a[1005][1005],b[1005][1005];
int n;

void solve(){
    n=read();
    memset(a,0,sizeof(a));
    rep(i,1,n-1)a[1][i]=1;
    rep(i,1,n-1)rep(j,1,n){
        int s=a[i-1][j]^a[i+1][j]^a[i][j-1]^a[i][j+1];
        a[i+1][j]=~s&1;
    }    
    int ans=0;
    rep(i,1,n)rep(j,1,n){
        b[i][j]=read();
        ans^=a[i][j]?b[i][j]:0;
    }
    print(ans,'\n');
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}