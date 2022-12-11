#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int n,t;
bool dp[2][10005];
int main(){
    int a[N],b[N];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int s=0; long long ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",a+i),s+=a[i];
            ans+=a[i]*a[i];
        }
        for(int i=0;i<n;i++){
            scanf("%d",b+i),s+=b[i];
            ans+=b[i]*b[i];
        }
        for(int i=1;i<=100*n;i++)
            dp[0][i]=0;
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            int p=i&1,q=p^1;
            for(int j=0;j<=100*n;j++){
                dp[q][j]=0;
                if(j>=a[i]) dp[q][j]|=dp[p][j-a[i]];
                if(j>=b[i]) dp[q][j]|=dp[p][j-b[i]];
            }
        }
        int d=1e9;
        for(int j=0;j<=100*n;j++){
            if(dp[n&1][j]) d=min(d,abs(s-2*j));
            // printf("%d : %d\n",j,(int)dp[n&1][j]);
        }
        // printf("%lld %d %d\n",ans,s,d);
        ans=ans*(n-2)+((s+d)*(s+d)+(s-d)*(s-d))/4;
        printf("%lld\n",ans);
    }
    return 0;
}