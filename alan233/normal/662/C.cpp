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

char a[20][100005];
int n,m;

ll S[1<<20],T[1<<20];

void FWT(ll *a,int opt){
    for(int mid=1;mid<(1<<n);mid<<=1){
        for(int i=0;i<(1<<n);i+=mid<<1){
            for(int j=0;j<mid;j++){
                ll x=a[i+j],y=a[i+j+mid];
                a[i+j]=x+y;
                a[i+j+mid]=x-y;
            }
        }
    }
    if(opt==-1){
        rep(i,0,(1<<n)-1)a[i]/=(1<<n);
    }
}

int main(){
    n=read(),m=read();
    rep(i,0,n-1)scanf("%s",a[i]);
    rep(j,0,m-1){
        int zip=0;
        rep(i,0,n-1)zip|=(a[i][j]-'0')<<i;
        S[zip]++;
    }
    rep(i,0,(1<<n)-1){
        int qwq=__builtin_popcount(i);
        T[i]=min(qwq,n-qwq);
    }
    FWT(S,1),FWT(T,1);
    rep(i,0,(1<<n)-1)S[i]=S[i]*T[i];
    FWT(S,-1);
    int ans=1e9;
    rep(i,0,(1<<n)-1)ckmin(ans,S[i]);
    print(ans,'\n');
    return 0;
}