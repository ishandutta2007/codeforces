#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=5e2+10;
int min(int a,int b){return a>b?b:a;}
int main(){
    int n,m,k,dp[N][2],temp,a[N],l,e,ans;
    char c[N];
    bool f=true;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<=k;i++)dp[i][0]=0;
    for(int i=0;i<n;i++){
        scanf("%s",c);
        temp=0;
        for(int j=0;j<m;j++)if(c[j]=='1')a[temp++]=j;
        if(temp==0)continue;
        l=min(temp-1,k);
        sort(a,a+temp);
        for(int j=0;j<=k;j++)dp[j][f]=N*N*N;
        for(int j=0;j<=l;j++){
            e=N;
            for(int r=0;r<=j;r++)e=min(e,a[r+temp-j-1]-a[r]+1);
            for(int r=j;r<=k;r++)dp[r][f]=min(dp[r][f],dp[r-j][!f]+e);
        }
        if(k>=temp)for(int j=temp;j<=k;j++)dp[j][f]=min(dp[j][f],dp[j-temp][!f]);

        f=!f;
    }
    f=!f;
    ans=dp[0][f];
    for(int i=1;i<=k;i++)ans=min(ans,dp[i][f]);
    printf("%d\n",ans);
}