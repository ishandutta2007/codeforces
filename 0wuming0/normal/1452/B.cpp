#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%lld",a+i);
        sort(a,a+n);
        ll sum=0;
        for(int i=0;i<n;i++)sum+=a[i];
        ll ans=0;
        ans=((n-1)-sum%(n-1))%(n-1);
        ans=max((n-1)*a[n-1]-sum,ans);
        cout<<ans<<endl;
    }
    return 0;
}