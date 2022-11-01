#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll x,t,a,b,da,db;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>x>>t>>a>>b>>da>>db;
    if(x==0)return cout<<"YES",0;
    for(ll i=0,aa=a;i<t;i++,aa-=da)
    {
        if(aa==x)return cout<<"YES",0;
        for(ll j=0,bb=b;j<t;j++,bb-=db)
        {
            if(bb==x)return cout<<"YES",0;
            if(aa+bb==x)
                return cout<<"YES",0;
        }

    }
    cout<<"NO";
    return 0;
}