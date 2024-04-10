#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[150005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
        a[i]+=a[i-1];
    }
    ll ans=1e18,j;
    for(int l=0,i=k;i<=n;l++,i++)
    {
        if(a[i]-a[l]<ans)
        {
            ans=a[i]-a[l];
            j=l+1;
        }
    }
    cout<<j<<endl;
    return 0;
}