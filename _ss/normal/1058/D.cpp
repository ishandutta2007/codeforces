#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;

ll ucln(ll a,ll b)
{
    ll r;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    if ((n*m*2)%k!=0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    ll t=ucln(n,k);
    k=k/t;
    ll x=n/t;
    t=ucln(m,k);
    k=k/t;
    ll y=m/t;
    if (k<2)
    {
        if (x*2<=n) x*=2; else y*=2;
    }
    cout<<0<<" "<<0<<endl<<0<<" "<<y<<endl<<x<<" "<<0;
    return 0;
}