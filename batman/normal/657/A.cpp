#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e14);
const ll MOD=((ll)1e9+7);
const ll N =300*1000;

ll n,d,h;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>d>>h;
    if(d>2*h || d<h || n<d+1 || (d==h && d==1 && n>2))return cout<<-1,0;
    for(int i=1;i<=h;i++)cout<<i<<" "<<i+1<<"\n";
    if(d==h)
    {
    	for(int i=d+2;i<=n;i++)cout<<2<<" "<<i<<"\n";
    	return 0;
	}
    if(h!=d)cout<<"1 "<<h+2<<"\n";
    for(int i=h+2;i<=d;i++)cout<<i<<" "<<i+1<<"\n";
    for(int i=d+2;i<=n;i++)cout<<1<<" "<<i<<"\n";
    
    return 0;
}