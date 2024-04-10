#include"bits/stdc++.h"
using namespace std;
int a[105][105];
int main()
{
    int t;
    cin>>t;
    while(t--)

    {
        int n;
        cin>>n;
        if(n==2)
        {
            cout<<-1<<endl;
            continue;
        }
        int now=1;
        for(int i=1;i<=n;i++)
        {
            a[i][i]=now++;
        }
        for(int k=1;k<n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                if(i+k>=1&&i+k<=n)
                a[i][i+k]=now++;
            }
            for(int i=1;i<=n;i++)
            {
                if(i+n-k>=1&&i+n-k<=n)
                a[i+(n-k)][i]=now++;
            }
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",a[i][j]," \n"[j==n]);

    }
    return 0;
}