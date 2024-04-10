#include<iostream>
#include<bitset>

using namespace std;

int n,k;

const int N = 105;
int a[N],b[N];
bitset<10001> dp[N*N];

int main()
{
    scanf("%d %d",&n,&k);
    dp[0][0] = 1;
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    for(int i=1;i<=n;++i)
        scanf("%d",b+i);
    for(int i=1;i<=n;++i)
    {
        for(int j=10000;j>=0;--j)
        {
            if(j>=b[i])
                dp[j] |= dp[j-b[i]]<<a[i];
        }
    }
    int ans = -1;
    for(int i=1;i<=10000;++i)
    {
        if(i*k<=10000 && dp[i][i*k])
            ans = max(ans,i*k);
    }
    printf("%d\n",ans);
}