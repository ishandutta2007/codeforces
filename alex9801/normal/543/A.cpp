#include <stdio.h>

int mem[501][501];
int tmp[501][501];

int arr[501];

int main()
{
    int r=0, n, m, b, mod, i, j, k;
    scanf("%d%d%d%d", &n, &m, &b, &mod);
    for(i=1;i<=n;i++)
        scanf("%d", &arr[i]);
    mem[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            for(k=0;k<=b;k++)
            {
                tmp[j][k]=mem[j][k];
                if(j&&k>=arr[i])
                    tmp[j][k]=(tmp[j][k]+tmp[j-1][k-arr[i]])%mod;
            }
        }
        for(j=0;j<=m;j++)
            for(k=0;k<=b;k++)
                mem[j][k]=tmp[j][k];
    }
    for(i=0;i<=b;i++)
        r=(r+mem[m][i])%mod;
    printf("%d", r);
    return 0;
}