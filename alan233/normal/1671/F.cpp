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

const int N=65;
const int mod=998244353;

inline void add(int &x,int y){
    if((x+=y)>=mod)x-=mod;
}
inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return res;
}

// f[i][j][k][las]: 1~i  j  k  p[i]>p[i+1] las 
int n=60,f[N][12][12][N],dp[12][12][N];

inline int Lagrange(int *coef,int pos){
    int ans=0;
    for(int i=1;i<=30;i++){
        int cf=coef[i],fm=1;
        for(int j=1;j<=30;j++)
            if(i!=j)
                cf=1ll*cf*(pos-j)%mod,fm=1ll*fm*(i-j+mod)%mod;
        ans=(ans+1ll*cf*qpow(fm))%mod;
    }
    return ans;
}

void solve(){
    int _n,m,k;
    scanf("%d%d%d",&_n,&m,&k);
    if(_n<=n)printf("%d\n",dp[m][k][_n]);
    else printf("%d\n",Lagrange(dp[m][k]+30,_n-30));
}

int main(){
    f[1][0][0][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=11;j++){
            for(int k=0;k<=11;k++){
                for(int las=1;las<=i-1;las++){
                    for(int now=1;now<=i;now++){
                        int newj=j+i-now;
                        int newk=k+(las>=now);
                        if(newj>11||newk>11)continue;
                        add(f[i][newj][newk][now],f[i-1][j][k][las]);
                    }
                }
            }
        }
    }
    for(int j=0;j<=11;j++){
        for(int k=0;k<=11;k++){
            for(int i=1;i<=n;i++){
                for(int las=1;las<=i;las++)
                    add(dp[j][k][i],f[i][j][k][las]);
            }
        }
    }
    int T=read();
    while(T--)solve();
    return 0;
}