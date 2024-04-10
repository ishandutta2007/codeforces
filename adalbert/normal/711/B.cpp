#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000][1000],sumi[1000],sumj[1000],zs,n,ans;
int main()
{
    cin>>n;
    if (n==1)
    {
        cout<<1;
        return(0);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        cin>>a[i][j];
    if (n==2)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (a[i][j]!=0 && ans==0) ans=a[i][j]; else
                if (a[i][j]!=0 && a[i][j]!=ans)
            {
                cout<<-1;
                return(0);
            }
        cout<<ans;
        return(0);

    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            sumi[i]+=a[i][j];
            sumj[j]+=a[i][j];
        }
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
        if (i!=j && sumi[i]==sumi[j])
    {
        zs=sumi[i];
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (a[i][j]==0 && ans==0)
    {

        if (sumi[i]==sumj[j] && sumi[i]<zs)
        {
            ans=zs-sumi[i];
            a[i][j]=ans;
            sumi[i]+=ans;
            sumj[j]+=ans;
        } else
        {
            cout<<-1;
            return(0);
        }
    }
    //cout<<ans<<'\n';
    for (int i=1;i<=n;i++)
    {
        sumi[i]=0;
        sumj[i]=0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            sumi[i]+=a[i][j];
            sumj[j]+=a[i][j];
        }
    for (int i=1;i<=n;i++)
    {
        if (sumi[i]!=zs)
        {
            cout<<-1;
            return(0);
        }
        if (sumj[i]!=zs)
        {
            cout<<-1;
            return(0);
        }
    }
    ll sum=0;
    for (int i=1;i<=n;i++)
        sum+=a[i][i];
    if (sum!=zs)
        {
            cout<<-1;
            return(0);
        }
    sum=0;
    for (int i=1;i<=n;i++)
        sum+=a[i][n-i+1]
        ;
    if (sum!=zs)
        {
            cout<<-1;
            return(0);
        }
    cout<<ans;
}