#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)

ll ans=1,p=1;
string s;

int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    for(ll i=1;i<s.size();i++)
    {
        if((s[i]-'0')+(s[i-1]-'0')==9)
            p++;
        else
            ans*=((p%2)?(p+1)/2:1ll),p=1;   
    }
    ans*=((p%2)?(p+1)/2:1ll),p=1;   
    cout<<ans;
    
    return 0;
}