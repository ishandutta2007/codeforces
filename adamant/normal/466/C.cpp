#include <bits/stdc++.h>

using namespace std;

#define int long long
main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n),pr(n+1);
    for(int i=0;i<n;i++) cin>>a[i],pr[i+1]=pr[i]+a[i];
    int sum=pr[n];
    if(sum%3)
    {
        cout<<0;
        return 0;
    }
    sum/=3;
    int ans=0;
    int cnt=0;
    for(int i=2;i<n;i++)
    {
        cnt+=pr[i-1]==sum;
        if(pr[n]-pr[i]==sum) ans+=cnt;
    }
    cout<<ans<<endl;
}