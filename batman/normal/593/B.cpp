#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define MOD ((ll)1e9+7)

ll n,x1,x2;
pair <ll,ll> a[N];

int main()
{
    cin>>n>>x1>>x2;
    for(int i=0;i<n;i++)
    {
        ll b,k;
        cin>>k>>b;
        a[i]={k*x1+b,k*x2+b};
        //cout<<a[i].first<<" "<<a[i].second<<"\n";
    }
    sort(a,a+n);
    //for(int i=0;i<n;i++)cout<<a[i].first<<" "<<a[i].second<<"\n";
    for(int i=0;i<n-1;i++)
    {
        if(a[i].second>a[i+1].second)
            return cout<<"YES",0;
    }
    cout<<"NO";
    return 0;
}