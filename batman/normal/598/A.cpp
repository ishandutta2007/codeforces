#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define N (301*1000)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

int main()
{
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll sum=n*(n+1)/2;
        ll p=1,x=0;
        while(p<=n)
            x++,p*=2;
        sum-=(tavan(2,x)-1);
        sum-=(tavan(2,x)-1);
        cout<<sum<<endl;    
    }
    return 0;
}