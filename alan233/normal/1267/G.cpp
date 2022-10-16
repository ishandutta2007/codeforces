// Author: wlzhouzhuan
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

double dp[105][10005];
int n,x,sum;

int main(){
    n=read(),x=read();
    dp[0][0]=1;
    rep(i,1,n){
        int V=read();
        sum+=V;
        per(j,i,1)
            rep(k,V,sum)
                dp[j][k]+=dp[j-1][k-V]*j/(n-j+1);
    }
    double ans=0.;
    rep(j,1,n){
        rep(k,0,sum)
            ans+=dp[j][k]*min(x/2.*(n/1./j+1),k/1./j);
    }
    printf("%.10f\n",ans);
    return 0;
}