#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,p,k;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>p>>k;
    if(p-k>1)cout<<"<< ";
    for(int i=max(1ll,p-k);i<p;i++)cout<<i<<" ";
    cout<<"("<<p<<") ";
    for(int i=p+1;i<=min(n,p+k);i++)cout<<i<<" ";
    if(p+k<n)cout<<">>";


    return 0;
}