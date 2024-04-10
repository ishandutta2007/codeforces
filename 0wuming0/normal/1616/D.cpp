#include"bits/stdc++.h"
using namespace std;
#define ll long long
int solve(ll a[],int n)
{
    if(n<=1)return 0;//for(int i=0;i<n;i++)cout<<a[i];cout<<"  "<<n<<endl;
    ll now=a[0];
    for(int i=1;i<n;i++)
    {
        if(now+a[i]<0)return 1+solve(a+i+1,n-i-1);
        now+=a[i];
        now=min(now,a[i]);
    }
    return 0;
}
ll a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",a+i);
        }
        ll x;
        cin>>x;
        for(int i=0;i<n;i++)
        {
            a[i]-=x;
        }
        cout<<n-solve(a,n)<<endl;
    }
    return 0;
}