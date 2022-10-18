#include <bits/stdc++.h>

using namespace std;

#define int long long

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin>>n;
    int xr=0,G[n+1];
    for(int i=0;i<n;i++)
        cin>>t,xr^=t;
    G[0]=0;
    for(int i=1;i<=n;i++)
    {
        G[i]=G[i-1]^(i);
        xr^=G[i-1]*(((n+1)/i)%2);
        if((n+1)%i-1>=0)
            xr^=G[(n+1)%i-1];
    }

    cout<<xr;
}