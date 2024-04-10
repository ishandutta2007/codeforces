#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1001*1000)
#define INF ((ll)1e7)

ll n;

int main ()
{
    cin>>n;
    cout<<(n/2)*((n+1)/2)<<"\n";
    for(int i=1;i<=n/2;i++)
        for(int j=n/2+1;j<=n;j++)
            cout<<i<<" "<<j<<"\n";
    return 0;
}