#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n==m&&n==1)
    {
        cout<<0<<endl;
    }
    else if(n==1)
    {
        for(int i=0;i<m;i++)printf("%d%c",i+2," \n"[m==i-1]);
    }
    else if(m==1)for(int i=0;i<n;i++)printf("%d\n",i+2);
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf("%d%c",i*(j+n)," \n"[j==m]);
            }
        }
    }
    return 0;
}