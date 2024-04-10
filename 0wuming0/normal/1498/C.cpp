#include"bits/stdc++.h"
using namespace std;
#define gcd __gcd
#define ll long long
long long a[1005];
ll mod=1e9+7;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<=n;i++)a[i]=0;
        ll ans=0;
        a[1]=1;
        for(int i=1;i<k;i++)
        {
            for(int j=1;j<=n;j++)ans+=a[j];
            ans%=mod;
            if(i%2)
            {
                for(int j=2;j<=n;j++)
                {
                    a[j]+=a[j-1];
                    a[j]%=mod;
                }
            }
            else
            {
                for(int j=n-1;j>=2;j--)
                {
                    a[j]+=a[j+1];
                    a[j]%=mod;
                }
                a[1]=0;
            }
        }
        for(int j=1;j<=n;j++)ans+=a[j];
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}