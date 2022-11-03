#include <bits/stdc++.h>

using namespace std;

#define fir first
#define sec second
#define pb push_back
#define int ll

typedef long long ll;

int a[300000],b[300000];

signed main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=1;i<=n;i++)
        if (a[i]>m)
        b[i]=1; else
        if (a[i]<m)
        b[i]=-1;

    for (int i=1;i<=n;i++)
        b[i]+=b[i-1];

    map<int,int> mp;

    int mid=1;

    while (a[mid]!=m)
        mid++;

    for (int i=0;i<mid;i++)
        mp[b[i]]++;
    int ans=0;
    for (int i=mid;i<=n;i++)
        ans+=mp[b[i]];

    mp.clear();
        for (int i=1;i<=n;i++)
        if (a[i]>m)
        b[i]=1; else
        if (a[i]<=m)
        b[i]=-1;

    for (int i=1;i<=n;i++)
        b[i]+=b[i-1];

    for (int i=0;i<mid;i++)
        mp[b[i]]++;

    for (int i=mid;i<=n;i++)
        ans+=mp[b[i]];

    cout<<ans;




}