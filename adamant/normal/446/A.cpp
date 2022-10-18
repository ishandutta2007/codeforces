#include <bits/stdc++.h>

using namespace std;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> l(n,1),r(n,1);
    for(int i=1;i<n;i++)    if(a[i]>a[i-1]) l[i]=l[i-1]+1;
    for(int i=n-2;i>=0;i--) if(a[i]<a[i+1]) r[i]=r[i+1]+1;
    int ans=1;
    for(int i=0;i<n;i++)
    {
        if(i && i<n-1)
        {
            if(a[i+1]-a[i-1]>1) ans=max(ans,l[i-1]+r[i+1]+1);
            else ans=max(ans,max(l[i-1]+1,r[i+1]+1));
        }
        else if(i) ans=max(ans,l[i-1]+1);
        else if(i<n-1) ans=max(ans,r[i+1]+1);
    }

    cout<<ans<<endl;

 }