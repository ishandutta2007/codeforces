#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)scanf("%lld",a+i);
        ll now=0,sum=0;
        sum+=a[0];
        for(int i=1;i<n;i++)
        {
            ll p=100*a[i];
            ll ans=p/k;
            if(p%k)ans++;
            now=max(now,ans-sum);
            //sum+now>=ans;
            sum+=a[i];
        }
        cout<<now<<endl;
    }
    return 0;
}