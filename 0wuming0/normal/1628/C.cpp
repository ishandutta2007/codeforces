#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[1005][1005];
int now[1005][1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            now[i][j]=0;
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        {
            if(now[i][j]==0)
            {
                now[i][j]^=1;
                now[i+1][j-1]^=1;
                now[i+1][j+1]^=1;
                now[i+2][j]^=1;
                ans^=a[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}