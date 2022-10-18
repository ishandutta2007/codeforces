#include <bits/stdc++.h>

using namespace std;

main()
 {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t,c;
    cin>>n>>t>>c;
    int cur=0;
    int x[n];
    for(int i=0;i<c;i++)
    {
        cin>>x[i];
        cur+=x[i]>t;
    }
    int ans=!cur;
    for(int i=c;i<n;i++)
    {
        cin>>x[i];
        cur+=x[i]>t;
        cur-=x[i-c]>t;
        ans+=!cur;
    }
    cout<<ans<<endl;
}