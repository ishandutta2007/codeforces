#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;

int n, m;
int a[N], b[N], t[N], l[N], r[N], d[N];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        b[i]=1e9;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>t[i]>>l[i]>>r[i]>>d[i];
        if(t[i]==1)
        {
            for(int j=l[i];j<=r[i];j++)
                a[j]+=d[i];
        }
        else
        {
            for(int j=l[i];j<=r[i];j++)
                b[j]=min(b[j], d[i]-a[j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=b[i];
    }
    int check=1;
    for(int i=1;i<=m;i++)
    {
        if(t[i]==1)
        {
            for(int j=l[i];j<=r[i];j++)
                a[j]+=d[i];
        }
        else
        {
            int max1=-1e9;
            for(int j=l[i];j<=r[i];j++)
                max1=max(max1, a[j]);
            if(max1!=d[i])
            {
                check=0;
                break;
            }
        }
    }
    if(check)
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<b[i]<<" ";
        }
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}