#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
#define N (301*1000)
#define INF ((ll)1e9)

ll n;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    if(n%2)return cout<<0,0;
    n/=2;
    if(n%2==0)return cout<<n/2-1,0;
    cout<<n/2;
    return 0;
}