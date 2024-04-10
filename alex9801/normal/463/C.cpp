#include <stdio.h>

int arr[2000][2000];
long long mem1[2000][2000];
long long mem2[2000][2000];


int main()
{
    int n,p,q,r,s,i,j;
    long long mx1=-1,mx2=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    for(i=0;i<n;i++)
    {
        mem1[0][0]+=arr[i][i];
        mem2[0][n-1]+=arr[i][n-1-i];
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            mem1[0][i]+=arr[j][i+j];
            mem2[0][n-1-i]+=arr[j][n-1-i-j];
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            mem1[i][0]+=arr[i+j][j];
            mem2[i][n-1]+=arr[i+j][n-1-j];
        }
    }
    for(i=1;i<n;i++)
        for(j=1;j<n;j++)
            mem1[i][j]=mem1[i-1][j-1];
    for(i=1;i<n;i++)
        for(j=0;j<n-1;j++)
            mem2[i][j]=mem2[i-1][j+1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((i+j)%2)
            {
                if(mem1[i][j]+mem2[i][j]-arr[i][j]>mx1)
                {
                    mx1=mem1[i][j]+mem2[i][j]-arr[i][j];
                    p=i+1;
                    q=j+1;
                }
            }
            else
            {
                if(mem1[i][j]+mem2[i][j]-arr[i][j]>mx2)
                {
                    mx2=mem1[i][j]+mem2[i][j]-arr[i][j];
                    r=i+1;
                    s=j+1;
                }
            }
        }
    }
    printf("%I64d\n%d %d %d %d",mx1+mx2,p,q,r,s);
    return 0;
}