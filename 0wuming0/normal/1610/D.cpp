#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll num[31];
ll _2[200005];
int main()
{
    _2[0]=1;
    for(int i=1;i<200005;i++)_2[i]=_2[i-1]*2%mod;
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a&1)
        {
            //
        }
        else
        {
            int k=0;
            while(a%2==0)
            {
                a/=2;
                k++;
            }
            num[k]++;
        }
    }
    {
        int sum=0;
        for(int i=30;i>=1;i--)
        {
            if(num[i])
            {
                ans+=_2[num[i]-1]*_2[sum]%mod;
            }
            sum+=num[i];
        }
    }
    ll sum=1;
    for(int i=1;i<=n;i++)sum=sum*2%mod;
    sum--;//cout<<sum<<" "<<ans<<endl;
    cout<<(sum-ans%mod+mod)%mod<<endl;
    return 0;
}