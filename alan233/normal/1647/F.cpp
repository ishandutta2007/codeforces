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

const int N=500005;
const int inf=1e9;

int a[N],n;

int dp1[N],dp2[N][2],dp3[N],ans;
void solve(){
    int mx=max_element(a+1,a+n+1)-a;
    memset(dp1,0x3f,4*(n+2));
    rep(i,0,n+2)dp2[i][0]=inf,dp2[i][1]=-inf;
    memset(dp3,0x3f,4*(n+2));
    dp1[1]=0;
    rep(i,2,mx){
        if(a[i-1]<a[i])
            ckmin(dp1[i],dp1[i-1]);
        if(dp1[i-1]<a[i])
            ckmin(dp1[i],a[i-1]);
        // printf("dp1[%d]=%d\n",i,dp1[i]);
    }
    dp3[n]=0;
    per(i,n,mx){
        if(a[i+1]<a[i])
            ckmin(dp3[i],dp3[i+1]);
        if(dp3[i+1]<a[i])
            ckmin(dp3[i],a[i+1]);
        // printf("dp3[%d]=%d\n",i,dp3[i]);
    }
    dp2[mx][0]=dp1[mx];
    rep(i,mx+1,n){
        if(a[i-1]>a[i])
            ckmin(dp2[i][0],dp2[i-1][0]);
        if(dp2[i-1][1]>a[i])
            ckmin(dp2[i][0],a[i-1]);
        if(a[i-1]<a[i])
            ckmax(dp2[i][1],dp2[i-1][1]);
        if(dp2[i-1][0]<a[i])
            ckmax(dp2[i][1],a[i-1]);
        // printf("dp2[%d][1]=%d\n",i,dp2[i][1]);
        if(dp2[i][1]>dp3[i])
            ans++;
    }
}

int main(){
    n=read();
    rep(i,1,n)a[i]=read();
    solve();
    reverse(a+1,a+n+1);
    solve();
    printf("%d\n",ans);
    return 0;
}