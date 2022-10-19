#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int change(int n)
{
    int i,j;
    int k=n*n;
    for(i=0;i<n;i++)
    {
        a[i][n]=k;
        k++;
        a[i][n+1]=k;
        k++;
        a[i][n+2]=k;
        k++;
        a[i][n+3]=k;
        k++;
    }
    for(i=0;i<n;i++)
    {
        a[n][i]=k;
        k++;
        a[n+1][i]=k;
        k++;
        a[n+2][i]=k;
        k++;
        a[n+3][i]=k;
        k++;
    }
    for(i=n;i<n+4;i++)for(j=n;j<n+4;j++)
        a[i][j]=k,k++;return 0;
}
int main()
{//int t=0;for(int i=1;i<28*28;i++)t^=i;cout<<t;
    int n;
    cin>>n;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            a[i][j]=4*j+i;
        }

    }
    int t=4;
    while(t<n)change(t),t+=4;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
/*

*/