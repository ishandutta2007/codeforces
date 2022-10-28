#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, m, ans=0;
int check[N];
char a[N][N];
set<int> active;

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        bool flag=0;
        for(int j=1;j<=n-1;j++)
        {
            if(!check[j] && a[j][i]>a[j+1][i])
            {
                flag=1;
                break;
            }  
        }
        ans+=flag;
        if(!flag)
        {
            for(int j=1;j<=n-1;j++)
            {
                if(a[j][i]<a[j+1][i])
                    check[j]=1;
            }
        }   
    }
    cout<<ans;
    return 0;
}