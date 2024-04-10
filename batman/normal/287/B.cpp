#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (300*1000)
#define INF ((ll)1e9)

ll a,k;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>k;

    if(a-1>k*(k-1)/2)return cout<<-1,0;
    a--;
    ll mn=1;
    ll mx=k;
    while(mx-mn>1){
        ll md=(mx+mn)/2;
        if(a>k*(k-1)/2-md*(md-1)/2)mx=md; else mn=md;
    }
    cout<<k-mx+(k*(k-1)/2-mx*(mx-1)/2 != a);
    return 0;
}