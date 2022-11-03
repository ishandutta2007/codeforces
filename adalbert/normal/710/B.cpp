#include <bits/stdc++.h>
using namespace std;
#define ll  long long
string st;
ll ans,a[4000000],sum[400000],imn,mn;
///---program start---///
int main()
{
    mn=10000000000000000000000;
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=n;i++)
    {
        ll ans=abs(a[i]*(i-1)-sum[i-1])+abs(sum[n]-sum[i]-a[i]*(n-i));
        if (ans<mn)
        {
            mn=ans;
            imn=a[i];
        }
    }
    cout<<imn;
}