#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define MOD ((ll)1e9+7)

ll a,b,c,x,y,z,ans;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>x>>y>>z;
    if(a>x)ans+=(a-x)/2;
    else ans-=(x-a);
    if(b>y)ans+=(b-y)/2;
    else ans-=(y-b);
    if(c>z)ans+=(c-z)/2;
    else ans-=(z-c);
    
    cout<<((ans>=0)?"Yes":"No");
    
    return 0;
}