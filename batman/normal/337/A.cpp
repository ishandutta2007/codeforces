#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000],ans;
int main()
{ 
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>a[i];
    sort(a,a+m);
    ans=a[n-1]-a[0];
    
    for(int i=n;i<m;i++)
        ans=min(ans,a[i]-a[i-n+1]);
    cout<<ans;
    return 0;
}