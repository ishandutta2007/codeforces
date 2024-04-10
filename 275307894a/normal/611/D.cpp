#include<cstdio>
#define mod 1000000007
#define K 50////
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
int n,m,k,x,y,z,flag,a[5039],now,ls,rs,mid,dp[5039][5039],ans,q[5039][5039]; 
unsigned long long q1[5039];
char s;
inline int check(register int x,register int y,register int l,register int r) {
    register int i;
    for(i=0; i+K+1<=y-x; i+=K+1) if(q1[x+i]!=q1[l+i]) break;
    for(;i<=y-x;i++)if(a[x+i]!=a[l+i]) return a[x+i]<a[l+i];
    return 0;
}
int main() {
    //freopen("split.in","r",stdin);
//  freopen("split.out","w",stdout);
    register int i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++) {
        s=getchar();
        while(s<'0'||s>'9') s=getchar();
        a[i]=s-'0';
    }
    for(i=1;i+K<=n;i++){
        for(j=i;j<=i+K;j++) q1[i]=q1[i]*10+a[j];
    }
    dp[0][0]=1;
    for(i=1; i<=n; i++) {
        dp[i][0]=1;q[i][0]=1;
        for(j=1; j<i; j++) {
            if(a[j+1]!=0) {
                now=2*j-i;
                if(now<0)dp[i][j]=q[j][j-1];
                else {
                    dp[i][j]=(q[j][j-1]-q[j][now]+mod)%mod;
                    if(check(now+1,j,j+1,i)) dp[i][j]=(dp[j][now]+dp[i][j])%mod;
                }
            }
            q[i][j]=(q[i][j-1]+dp[i][j])%mod;
        }
    }
    printf("%d\n",q[n][n-1]);
}