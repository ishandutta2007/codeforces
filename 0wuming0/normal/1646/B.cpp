#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[200005];
ll sum[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%lld",a+i);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
        for(int i=1;;i++)
        {
            if(i+1+i>n)break;
            if(sum[i+1]<sum[n]-sum[n-i])
            {
                cout<<"YES"<<endl;
                goto ne;
            }
        }
        cout<<"NO"<<endl;
        ne:;
    }
    return 0;
}