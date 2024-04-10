#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1001*1000)
#define INF ((ll)1e7)

ll n,b,a[N],ans;

int main ()
{
    cin>>n>>b;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            ans=max(ans,(ll)(b/a[i])*a[j]+(b%a[i]));
    cout<<max(ans,b);
    return 0;
}