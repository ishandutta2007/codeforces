#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define N (1555)
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

ll a,b,r;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b>>r;
    cout<<((2*r>a || 2*r>b)?"Second":"First");      
    return 0;
}