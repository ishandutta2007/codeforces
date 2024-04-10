#include"bits/stdc++.h"
using namespace std;
#define ll long long
int t=720720;
int n,m;
int a[505][505];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        scanf("%d",&a[i][j]);
        if((i+j)%2)a[i][j]=t;
        else a[i][j]=t-a[i][j]*a[i][j]*a[i][j]*a[i][j];
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)printf("%d%c",a[i][j]," \n"[j==m-1]);
    return 0;
}