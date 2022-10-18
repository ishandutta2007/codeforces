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
    int n;
    cin>>n;
    string a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    int c[n];
    for(int i=0;i<n;i++) cin>>c[i];
    string last="";
    for(int i=0;i<n;i++)
    {
        int x=c[i]-1;
        if(a[x]>b[x]) swap(a[x],b[x]);
        if(a[x]>=last)
            last=a[x];
        else if(b[x]>=last)
            last=b[x];
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}