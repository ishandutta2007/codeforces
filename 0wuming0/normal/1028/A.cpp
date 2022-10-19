#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,m;
    char a[150][150];
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    int l,r;
    l=r=-1;int i,j;
    for(i=0;i<n;i++)for(j=0;j<m;j++)
    {
        if(a[i][j]=='B')goto out;
    }out://cout<<i<<j<<endl;
    for(int k=i;;k++)
    {
        if(a[k][j]!='B')
        {
            l=(k-i)/2;//cout<<k<<endl;
            break;
        }
    }
    cout<<i+l+1<<" "<<j+l+1<<endl;
    return 0;
}