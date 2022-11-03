#include <bits/stdc++.h>
using namespace std;
#define ll long long
///----------------------------------------------------------///


ll a[100000],type,y,ans,n,m;

///----------------------------------------------------------///
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>type>>y;
        a[type-1]+=y-1;
        a[type+1]+=a[type]-y;
        a[type]=0;
    }
    for (int i=1;i<=n;i++)
        cout<<a[i]<<'\n';
}