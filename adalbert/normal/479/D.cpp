#include <bits/stdc++.h>
using namespace std;
long long mn,mx,n,k,imx,imn,l,x,y,a[300000],kx,ky,ans1,ans2,ans3,ans4;
map <long long ,long long >mp;
int main()
{
    cin>>n>>l>>x>>y;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i],
        mp[a[i]]=1;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
    {
        if (mp[a[i]-x]==1) kx++;
        if (mp[a[i]-y]==1) ky++;
        if (mp[a[i]-y+x]==1 && (a[i]-y>=0))
        {
            ans1=a[i]-y;
        }
        if (mp[a[i]-x+y]==1 && (a[i]+y<=l))
        {
            ans2=a[i]+y;
        }
        if (mp[a[i]+x+y]==1)
        {
            ans3=a[i]+x;
        }
        if (mp[a[i]-x-y]==1)
        {
            ans4=a[i]-x;
        }

    }
    if (kx!=0 && ky!=0) cout<<0; else
    if (kx!=0 || ky!=0)
    {
        cout<<1<<'\n';
        if (kx!=0) cout<<y; else cout<<x;
    } else
    if (ans1!=0)
    {
        cout<<1<<'\n';
        cout<<ans1;
    } else
    if (ans2!=0)
    {
        cout<<1<<'\n';
        cout<<ans2;
    } else
    if (ans3!=0)
    {
        cout<<1<<'\n';
        cout<<ans3;
    } else
    if (ans4!=0)
    {
        cout<<1<<'\n';
        cout<<ans4;
    } else
    {
        cout<<2<<'\n';
        cout<<x<<' '<<y;
    }
}