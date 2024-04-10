#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("avx","avx2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
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
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=20;

ll dp[N][N];
char a[N],b[N];
void solve(){
    scanf("%s%s",a+1,b+1);
    int n=strlen(a+1),m=strlen(b+1);
    rep(i,1,n)a[i]-='0';
    rep(i,1,m)b[i]-='0';
    //alen>=blen
    rep(prea,0,min(n,m)){
        bool ok=1;
        rep(i,1,prea)if(a[i]!=b[i])ok=0;
        if(!ok)break;
        memset(dp,-1,sizeof(dp));
        dp[prea][prea]=0;
        rep(i,prea+1,n){
            rep(j,prea+1,m){
                if(i&&j&&dp[i-1][j-1]!=-1&&a[i]<=b[j]){
                    dp[i][j]=dp[i-1][j-1]*10+b[j]-a[i];
                }
                if(i&&j>1&&dp[i-1][j-2]!=-1&&b[j-1]==1&&a[i]>b[j]){
                    dp[i][j]=dp[i-1][j-2]*10+10+b[j]-a[i];
                }
            }
        }
        if(dp[n][m]!=-1){
            printf("%lld\n",dp[n][m]);
            return;
        }
    }
    //blen>alen
    rep(preb,0,m){
        memset(dp,-1,sizeof(dp));
        ll head=0;
        rep(i,1,preb)head=10ll*head+b[i];
        dp[0][preb]=head;
        rep(i,1,n){
            rep(j,preb+1,m){
                if(i&&j&&dp[i-1][j-1]!=-1&&a[i]<=b[j]){
                    dp[i][j]=dp[i-1][j-1]*10+b[j]-a[i];
                }
                if(i&&j>1&&dp[i-1][j-2]!=-1&&b[j-1]==1&&a[i]>b[j]){
                    dp[i][j]=dp[i-1][j-2]*10+10+b[j]-a[i];
                }
            }
        }
        if(dp[n][m]!=-1){
            printf("%lld\n",dp[n][m]);
            return;
        }
    }
    puts("-1");
}
int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}