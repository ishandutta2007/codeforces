#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=305;

int n;
int a[N][N];
int b[N], ans[N];

int32_t main()
{ 
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==i)
                continue;
            int check=1;
            for(int k=1;k<=n;k++)
            {
                if(b[k]==a[i][j])
                    break;
                if(b[k]==i)
                    continue;
                if(b[k]<a[i][j])
                {
                    check=0;
                    break;
                }
            }
            if(check)
            {
                ans[i]=a[i][j];
                break;
            }  
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}