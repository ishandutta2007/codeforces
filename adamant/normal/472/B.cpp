#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

main()
{
#ifndef ONLINE_JUDGE
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int f[n];
    for(int i=0;i<n;i++) cin>>f[i];
    sort(f,f+n);
    int ans=0;
    for(int i=0;i<n;i+=k)
        ans+=2*(f[n-1-i]-1);
    cout<<ans<<endl;
}