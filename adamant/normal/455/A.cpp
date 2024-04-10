#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn=1e5+2;

int b[maxn][2];

main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[a[i]][1]++;
    }
    int ans=b[1][1];
    for(int i=2;i<=maxn;i++)
    {
        b[i][1]*=i;
        b[i][0]+=max(b[i-1][1],b[i-1][0]);
        b[i][1]+=b[i-1][0];
        ans=max(ans,max(b[i][1],b[i][0]));
    }
    cout<<ans<<endl;

}