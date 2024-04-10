#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e3+5;

int a[N], f[10];

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    if(!f[0])
        return cout<<"-1", 0;
    for(int i=1;i+8<=f[5];i+=9)
        for(int j=1;j<=9;j++)
            cout<<"5";
    for(int i=1;i<=f[0];i++)
    {
        cout<<"0";
        if(f[5]<=8)
            break;
    }
    return 0;
}