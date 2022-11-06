#include <stdio.h>

int arr[5][1001];
int loc[1002][5];
int mem[1000][1001];

int main()
{
    bool u;
    int n,k,t,i,j,l;
    scanf("%d%d",&n,&k);
    for(i=0;i<k;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    for(i=0;i<k;i++)
        arr[i][n]=n+1;
    for(i=0;i<k;i++)
        for(j=0;j<=n;j++)
            loc[arr[i][j]][i]=j;
    t=0;
    for(i=0;i<k;i++)
        loc[arr[0][0]][i]>t?loc[arr[0][0]][i]:t;
    for(i=1;i<=n;i++)
    {
        u=1;
        for(j=1;j<k;j++)
        {
            if(loc[arr[0][i]][j]<loc[arr[0][0]][j])
            {
                u=0;
                break;
            }
        }
        if(u)
            mem[0][i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            mem[i][j]=mem[i-1][j];
            u=1;
            for(l=1;l<k;l++)
            {
                if(loc[arr[0][j]][l]<loc[arr[0][i]][l])
                {
                    u=0;
                    break;
                }
            }
            if(u)
                mem[i][j]=mem[i-1][i]+1>mem[i][j]?mem[i-1][i]+1:mem[i][j];
        }
    }
    printf("%d",mem[n-1][n]);
    return 0;
}