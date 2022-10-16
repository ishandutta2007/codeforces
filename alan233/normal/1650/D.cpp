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

const int N=2005;

int ans[N],a[N],b[N],n;

void solve(){
    n=read();
    rep(i,1,n)a[i]=read(),ans[i]=0;
    per(i,n,1){
        int pos=0;
        rep(j,1,i)if(a[j]==i){pos=j;break;}
        ans[i]=pos%i;
        memcpy(b,a,sizeof(a));
        for(int j=1;j<=pos;j++)b[i-pos+j]=a[j];
        for(int j=pos+1;j<=i;j++)b[j-pos]=a[j];
        memcpy(a,b,sizeof(b));
        // printf("when i=%d\n",i);
        // rep(j,1,n)printf("%d ",a[j]);puts("");
    }
    rep(i,1,n)printf("%d ",ans[i]);puts("");
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}