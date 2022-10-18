#include <bits/stdc++.h>

using namespace std;

main()
 {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int t=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==-1 && !t) ans++;
        else t+=x;
    }
    cout<<ans<<endl;
}