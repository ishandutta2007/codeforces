#include"bits/stdc++.h"
using namespace std;
#define i0 dwada
#define j0 afgh
int a[1005][1005];
int b2[1005][1005];
int c2[1005][1005];
int c5[1005][1005];
int b5[1005][1005];
int flag=0;
int i0,j0;
int in(int k,int p)
{
    if(k==0)
    {
        flag=1;
        return 1;
    }
    int ans=0;
    while(k%p==0)k/=p,ans++;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
    }
    int k=0,l=0;
#define b b2
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)b[i][j]=in(a[i][j],2);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)c2[i][j]=b2[i][j];
    for(int i=n-2;i>=0;i--)
    {
        b[i][n-1]+=b[i+1][n-1];
        b[n-1][i]+=b[n-1][i+1];
    }
    for(int i=n-2;i>=0;i--)for(int j=n-2;j>=0;j--)
    {
        b[i][j]+=min(b[i+1][j],b[i][j+1]);
    }
    k=b[0][0];
#undef b
#define b b5
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)b[i][j]=in(a[i][j],5);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)c5[i][j]=b5[i][j];
    for(int i=n-2;i>=0;i--)
    {
        b[i][n-1]+=b[i+1][n-1];
        b[n-1][i]+=b[n-1][i+1];
    }
    for(int i=n-2;i>=0;i--)for(int j=n-2;j>=0;j--)
    {
        b[i][j]+=min(b[i+1][j],b[i][j+1]);
    }
    l=b[0][0];
#undef b
    if(flag==1&&l>=1&&k>=1)
    {
        cout<<1<<endl;
        for(i0=0;i0<n;i0++)for(j0=0;j0<n;j0++)if(a[i0][j0]==0)goto ne;
        ne:;
        for(int i=0;i<i0;i++)putchar('D');
        for(int j=0;j<j0;j++)putchar('R');
        for(int i=i0;i<n-1;i++)putchar('D');
        for(int i=j0;i<n-1;i++)putchar('R');
    }
    else if(l>k)
    {
        cout<<k<<endl;
        int i=0,j=0;
        while(i!=n-1||j!=n-1)
        {
            if(i==n-1)
            {
                putchar('R'),j++;
                continue;
            }
            if(j==n-1)
            {
                putchar('D'),i++;
                continue;
            }
            if(b2[i][j]-c2[i][j]==b2[i+1][j])putchar('D'),i++;
            else putchar('R'),j++;
        }
    }
    else
    {
        cout<<l<<endl;
        int i=0,j=0;
        while(i!=n-1||j!=n-1)
        {
            if(i==n-1)
            {
                putchar('R'),j++;
                continue;
            }
            if(j==n-1)
            {
                putchar('D'),i++;
                continue;
            }
            if(b5[i][j]-c5[i][j]==b5[i+1][j])putchar('D'),i++;
            else putchar('R'),j++;
        }
    }
    return 0;
}