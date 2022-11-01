#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)

ll n,a[N],dpl[2][N],dpr[2][N],ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++)cin>>a[i];
    dpl[0][2]=a[1],dpl[1][2]=a[1]-(a[1]&1);
    for(int i=3;i<=n;i++)
    {
        if(a[i-1]>1)dpl[1][i]=a[i-1]-(a[i-1]&1)+dpl[1][i-1];
        dpl[0][i]=max(a[i-1]-(!(a[i-1]&1))+dpl[0][i-1],dpl[1][i]);
    }
    
    dpr[0][n-1]=a[n-1],dpr[1][n-1]=a[n-1]-(a[n-1]&1);
    for(int i=n-2;i>=1;i--)
    {
        if(a[i]>1)dpr[1][i]=a[i]-(a[i]&1)+dpr[1][i+1];
        dpr[0][i]=max(a[i]-(!(a[i]&1))+dpr[0][i+1],dpr[1][i]);
    }
        
    //for(int i=0;i<n;i++)
    //  cout<<dpl[0][i]<<" "<<dpl[1][i]<<" "<<dpr[0][i]<<" "<<dpr[1][i]<<"\n";  
    for(int i=0;i<=n+1;i++)
        ans=max(ans,max(max(dpl[1][i]+dpr[0][i],dpl[0][i]+dpr[1][i]),dpr[1][i]+dpl[1][i]));
    cout<<ans;          
    return 0;
}