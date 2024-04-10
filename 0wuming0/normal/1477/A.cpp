#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[200005];
ll gcd(ll x,ll y)
{
    if(x==0||y==0)return x+y;
    return gcd(y,x%y);
}
int main()
{
    int n;
    int t;
    ll k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>k;
        for(int i=0;i<n;i++)scanf("%lld",a+i);//
        for(int i=1;i<n;i++)a[i]-=a[0];
        ll ans=a[1];k-=a[0];
        for(int i=2;i<n;i++)
        {
            ans=gcd(abs(ans),abs(a[i]));
        }
        if(ans==0)
        {
            if(k==0)cout<<"yes"<<endl;
            else cout<<"no"<<endl;
            continue;
        }//cout<<"ok"<<endl;
        if(k%ans==0)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}