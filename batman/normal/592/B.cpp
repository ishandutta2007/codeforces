#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define MOD ((ll)1e9+7)

ll n;

int main()
{
    cin>>n;
    cout<<(n-2)*(n-2);
    return 0;
}