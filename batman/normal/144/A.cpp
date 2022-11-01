#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)

ll n,a[N],mini=INF,min_id,maxi,max_id;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=mini)mini=a[i],min_id=i;
        if(a[i]>maxi)maxi=a[i],max_id=i;
    }
    ll ans=max_id+n-1-min_id;
    if(max_id>min_id)ans--;
    cout<<ans;
    return 0;
}