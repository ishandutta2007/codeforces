#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)

ll k,a[20];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k;
    for(int i=0;i<12;i++)cin>>a[i];
    sort(a,a+12);
    if(k==0)return cout<<0,0;
    for(int i=11,sum=0;i>=0;i--)
    {
        sum+=a[i];
        if(sum>=k)
            return cout<<12-i,0;
    }
    cout<<-1;
    return 0;
}