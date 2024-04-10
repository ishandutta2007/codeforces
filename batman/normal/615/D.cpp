#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (201*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,a[N],ans=1,t=1;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll b;
        cin>>b;
        a[b]++;
    }
    for(ll i=2;i<N;i++)
        if(a[i])
        {
            ll ex=ans;
            ans%=MOD;
            for(ll p=i,q=0;q<a[i];q++,p*=i,p%=MOD)
                ans*=tavan(p,t,MOD),ans%=MOD,ans*=ex,ans%=MOD;
            t*=a[i]+1;
            t%=MOD-1;
        }
    cout<<ans;
    return 0;
}