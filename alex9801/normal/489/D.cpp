#include <stdio.h>
#include <string.h>
#include <vector>

std::vector<int> arr[3001];
int cnt[3001];

int main()
{
    int n,m,a,b,i,j,k;
    long long r=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        arr[a].push_back(b);
    }
    for(i=1;i<=n;i++)
    {
        memset(cnt,0,sizeof(cnt));
        for(j=0;j<arr[i].size();j++)
            for(k=0;k<arr[arr[i][j]].size();k++)
                cnt[arr[arr[i][j]][k]]++;
        for(j=1;j<=n;j++)
            if(i!=j)
                r+=cnt[j]*(cnt[j]-1)/2;
    }
    printf("%I64d",r);
    return 0;
}