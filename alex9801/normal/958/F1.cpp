#include<bits/stdc++.h>
using namespace std;

int arr[110];
int res[110];
int cnt[110];

int main()
{
    int n, m, i, j, k;
    int sum = 0;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++)
        scanf("%d", &arr[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d", &res[i]);
        sum += res[i];
    }
    
    for(i=1;i<=n-sum+1;i++)
    {
        memset(cnt, 0, sizeof cnt);
        for(j=i;j<i+sum;j++)
            cnt[arr[j]]++;
        
        bool ok = 1;        
        for(j=1;j<=m;j++)
        {
            if(cnt[j] != res[j])
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}