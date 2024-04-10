#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
ll a[3];
ll gcd(ll a,ll b)
{
    while (b)
    {
        ll r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ll n,m,q;
    cin>>n>>m>>q;
    ll t=gcd(n,m);
    a[1]=n/t;
    a[2]=m/t;
    for (int i=1;i<=q;i++)
    {
        pii s,e;
        cin>>s.fi>>s.se>>e.fi>>e.se;
        if ((s.se-1)/a[s.fi]==(e.se-1)/a[e.fi]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}