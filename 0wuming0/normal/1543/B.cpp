#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }
        ll ans=(sum%n)
        *
        (n-sum%n);/*
        for(int i=0;i<n;i++)
        {
            ans+=abs((sum+i)/n-a[i]);
        }*/
        printf("%lld\n",ans);
    }
    return 0;
}