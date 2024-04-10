#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int n, m, k;
    cin>>n>>m>>k;
    cout<<m*(m-1)/2<<endl;
    if(k==0)
    {
        for(int i=1;i<m;i++)
        {
            for(int j=i+1;j<=m;j++)
            {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    else
    {
        for(int i=1;i<m;i++)
        {
            for(int j=i+1;j<=m;j++)
            {
                cout<<j<<" "<<i<<endl;
            }
        }
    }
    return 0;
}